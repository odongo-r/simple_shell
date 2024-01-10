#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_TOKENS 100

/**
 * Description-  Tokenizes a command string into an array of tokens.
 *
 * @param- command The command string to tokenize.
 * @return- An array of tokens, or NULL on error.
 */
char **tokenize(char *command)
{
	static char *tokens[MAX_TOKENS];
	int token_count = 0;

	char *token = strtok(command, " ");

	while (token != NULL && token_count < MAX_TOKENS)
	{
		tokens[token_count++] = token;
		token = strtok(NULL, " ");
	}

	tokens[token_count] = NULL;

	return (tokens);
}

/**
 * Main- function for the simple shell.
 *
 * @param- argc Argument count.
 * @param- argv Argument vector.
 * @return- 0 on success, non-zero on error.
 */
int main(int argc, char **argv)
{
	char *command;
	char **args;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		command = fgets(command, 1024, stdin);

		if (command == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		args = tokenize(command);

		pid_t pid = fork();

		if (pid < 0)
		{
			perror(argv[0]);
		}
		else if (pid == 0)
		{
			execve(args[0], args, environ);
			perror(argv[0]);
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
