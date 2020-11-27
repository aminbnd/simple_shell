#include "header.h"
/**
  *process - Allows the process to execute
  *another program
  *@argv: array of stings
  *Return: integer, 1 on success
  */
int process(char **argv)
{
	pid_t pid;
	/*pid_t w;*/
	int status;

	pid = fork(); /* Error forking */
	if (pid == -1)
	{
		perror("Error:");
		return (-1);
	}

	if (pid == 0) /* child process */
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("Error:");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	/*else*/
	/*{*/
		wait(&status);
	/*}*/
	return (1);
}
