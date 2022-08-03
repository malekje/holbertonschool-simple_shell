#include "main.h"

int main(void)
{

	char *ln, **command;
	int st;
	do
	{
		if (isatty(STDIN_FILENO))
			write(STDERR_FILENO, "$ ", 2);

		else
		{
			ln = getln();
			command = formatln(ln);
			search_exe(command);
			launch_process(command);
			free(ln);
			free(command);
			return 0;
		}

		ln = getln();
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
