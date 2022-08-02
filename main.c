#include "main.h"

int main(void)
{

	char *ln, **command;
	int st = 0;

	do
	{
		printf("$ ");
		ln = getln();
		int st;
		command = formatln(ln);

		if (*command == NULL)
		{
			free(ln);
			free(command);
			continue;
		}
		search_exe(command);
		st = launch_process(command);
		free(ln);
		free(command);

	} while (st);

	return 0;
}
int launch_process(char **command)
{
	pid_t pid;

	pid = fork();
	if (pid == 0 && execve(command[0], command, environ) == -1)
		perror("./shell");

	else
		wait(&pid);

	return (1);
}
