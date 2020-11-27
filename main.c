#include "header.h"
/**
  *main - entry point
  *Return: 0
  */
int main(void)
{
	char *line;
	char **args;
	int statue = 1;

	while (statue)
	{
		prompt();
		line = readline();
		args = split_line(line);
		if (strcmp(line, "exit") == 0)
			exit(0);
		process(args);
		free(line);
		free(args);
	}
	return (0);
}
