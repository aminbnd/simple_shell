#ifndef HEADER_H
#define HEADER_H

/**** libraries ****/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


/**** functions ****/
int _putchar(char c);
void prompt(void);
char *readline(void);
char **split_line(char *line);
int process(char **argv);
int execute(char **argv);

/**** macros ****/
#define DELIMITERS " \n\t\a\r"

#endif
