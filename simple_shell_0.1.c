#include "main.h"

void execute_command(char *line)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execlp(line, line, (char *)NULL) == -1)
		{
			/* Print error message if executable is not found */
			fprintf(stderr, "./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

int main(void)
{
	char *line;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove newline character at the end */
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}

		execute_command(line);
	}

	free(line);
	return 0;
}
