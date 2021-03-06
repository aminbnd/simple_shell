			SIMPLE SHELL : A LINUX SHELL CLONE

				

.\" Manpage for Simple Shell.
. man 1 "nov 25 2020" "1.0" "Simple Shell Man Page"
. NAME
simple_shell - simple_shell is an sh-compatible command language interpreter that executes commands from the stand input or from a file.
. SYNOPSIS
simple_shell [command_string | file]

. DESCRIPTION
simple_shell is an sh-compatible command language interpreter that executes commands read from the standard input or from a file.h.

simple_shell is intended to be a conformant implementation of the Shell and Utilities portion of the IEEE POSIX specification (IEEE Standard 1003.1). simple_shell can be configured to be POSIX-conformant by default.
. Overview
The simple_shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.  It is the program that is running when the user runs gcc -Wall -Werror -Wextra -pedantic *.c -o hsh and runs the executable file, ./hsh. The simple_shell implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with built in history and line editing capabilities.  It incorporates many features to aid interactive use and has the advantage that the interpretative language is common to both interactive and non-interactive use (shell scripts).  That is, commands can be typed directly to the running shell or can be put into a file and the file can be executed directly by the shell.

. Aliases
 An alias is a name and corresponding value set using the alias(1) builtin command.  Whenever a reserved word may occur (see above), and after checking for reserved words, the shell checks the word to see if it matches an alias.  If it does, it replaces it in the input stream with its value.  For example, if there is an alias called “lf” with the value “ls -F”, thenthe input:

      lf foobar ⟨return⟩

would become

      ls -F foobar ⟨return⟩

Aliases provide a convenient way for naive users to create shorthands for commands without having to learn how to create functions with arguments.  They can also be used to create lexically obscure code. This use is discouraged.


. Simple Commands
 If a simple command has been recognized, the shell performs the following actions:

 1.   Leading words of the form “name=value” are stripped off and assigned to the environment of the simple command.  Redirection operators and their arguments (as described below) are stripped off and saved for processing.

 2.   The remaining words are expanded as described in the section called “Expansions”, and the first remaining word is considered the command name and the command is located.  The remaining words are considered the arguments of the command.  If no command name resulted, then the “name=value” variable assignments recognized in item 1 affect the current shell.


. Builtins
This section lists the builtin commands which are builtin because they need to perform some operation that can't be performed by a separate process.

. alias [name[=string ...]]
If name=string is specified, the shell defines the alias name with value string.  If just name is specified, the value of the alias name is printed.  With no arguments, the alias builtin prints the names and values of all defined aliases (see unalias).

. cd [-LP] [directory]
Switch to the specified directory (default HOME).  If an entry for CDPATH appears in the environment of the cd command or the shell variable CDPATH is set and the directory name does not begin with a slash, then the directories listed in CDPATH will be searched for the specified directory.  The format of CDPATH is the same as that of PATH.  If a single dash is specified as the argument, it will be replaced by the value of OLDPWD.  The cd command will print out the name of the directory that it actually switched to if this is different from the name that the user gave.  These may be different either because the CDPATH mechanism was used or because the argument is a single dash.  The -P option causes the physical directory structure to be used, that is, all symbolic links are resolved to their respective values.  The -L option turns off the effect of any preceding -P options.


. env  [-] [NAME=VALUE]... [COMMAND [ARG]...]
Prints out the current environment.

. exit [exitstatus]
Terminate the shell process.  If exitstatus is given it is used as the exit status of the shell; otherwise the exit status of the preceding command is used.

. help [PATTERN ...]
Display information about builtin commands.

. history
Display the history list with line numbers.

. setenv [VARIABLE] [VALUE]
The setenv() built-in adds the variable name to the environment with the value value, if name does not already exist. If name does exist in the environment, then its value is changed to value if overwrite is nonzero; if overwrite is zero, then the value of name is not changed. This function makes copies of the strings pointed to by name and value.

. unsetenv [VARIABLE]

The unsetenv() built-in deletes the variable name from the environment. If name does not exist in the environment, then the functionsucceeds, and the environment is unchanged.

. unalias [-a] [name]

If name is specified, the shell removes that alias.  If -a is specified, all aliases are removed.

.EXAMPLE 

To run the simple shell, compile all the *.c files using gcc -Wall -Wextra -Werror -pedantc *.c -o hsh
Then, test a command. for example:

./hsh 
$ ls -l
total 64
-rwxrwxr-x 1 amin amin 9488 nov.  27 11:55 a.out
-rw-r--r-- 1 amin amin  222 nov.  25 20:24 AUTHORS
-rw-r--r-- 1 amin amin  410 nov.  25 12:55 header.h
-rwxrwxr-x 1 amin amin 9216 nov.  27 11:52 hsh
-rw-rw-r-- 1 amin amin  313 nov.  27 11:59 main.c
-rw-r--r-- 1 amin amin 5407 nov.  25 12:25 man_1_simple_shell
-rw-r--r-- 1 amin amin  522 nov.  27 11:56 processing.c
-rw-r--r-- 1 amin amin  237 nov.  25 13:05 purchar.c
-rw-r--r-- 1 amin amin 5514 nov.  27 12:22 README.md
-rw-r--r-- 1 amin amin 1247 nov.  27 11:56 steps.c
$

.BUGS

No known bugs.

.AUTHOR

khalil hassayoun and med amine bondi

.project for :
<br><br/>
<img src="https://www.holbertonschool.com/holberton-logo.png"/>

