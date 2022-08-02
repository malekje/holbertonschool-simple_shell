#include "main.h"

int main(void)
{

	char *ln, **command;

	while (1)
	{
		printf("$ ");
		ln = getln();
		command = formatln(ln);
		if (*command == NULL)
			continue;
		search_exe(command);
		launch_process(command);
		free(ln);
		free(command);
	}

	return (0);
}
