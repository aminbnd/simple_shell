#include "header.h"

/**
  *prompt - prints a prompt
  *Return: void
  */
void prompt(void)
{
	_putchar('$');
	_putchar(' ');
}

/**
  *readline - writes a prompt and reads line from
  *stdin (does not print the line read)
  *Return: string (the read line)
  */
char *readline(void)
{
	char *line = NULL;
	size_t size = 0;
	int i;

	if (getline(&line, &size, stdin) == EOF)
	{
		for (i = 0; line[i]; i++)
		{
			if (line[i] == -1)
			{
				exit(EXIT_SUCCESS); /* EOF received */
			}
			else
			{
				perror("readline");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
	}
	/* line freed in the looper function */
	return (line);
}

/**
  *split_line - splits line into tokens
  *(does not print the tokens)
  *@line: string (entred line)
  *Return: array of stings (tokens)
  */
char **split_line(char *line)
{
	int bufsize = 1024;
	int pos = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("allocation error:");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMITERS);
	while (token != NULL)
	{
		tokens[pos] = token;
		/*printf("%s\n", tokens[pos]);just for testing*/
		pos++;
		token = strtok(NULL, DELIMITERS);
	}
	tokens[pos] = NULL;
	/* tokens freed in a later function */
	return (tokens);
}

