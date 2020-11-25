#include "header.h"
/**
  *main - entry point
  *Return: 0
  */
int main(void)
{
	char *line;
	char **args;
	int status;

	while (status)
	{
		prompt();
		line = readline();
		args = split_line(line);
		status = process(args);

		free(line);
		free(args);
	}
	return (0);
}
