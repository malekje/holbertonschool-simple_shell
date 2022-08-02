#include "main.h"

#define TOKEN_DELIM " \t\r\n\a"
char **formatln(char *ln)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		perror("failed to allocate tokens\n");
		return NULL;
	}

	token = strtok(ln, TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				perror("failed to reallocate tokens\n");
				return NULL;
			}
		}

		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

char *getln(void)
{

	char *ln = NULL;
	unsigned long bufsize = 0;

	getline(&ln, &bufsize, stdin);

	return (ln);
}

void launch_process(char **command)
{
	pid_t pid;

	pid = fork();
	if (pid == 0 && execve(command[0], command, environ) == -1)
		perror("./shell");

	else
		wait(&pid);
}
