#include "main.h"
char *_getenv(char *name)
{
	int i = 0;
	char *val;

	unsigned long lenValue, lenName = strlen(name);
	lenValue = strlen(environ[i]) - lenName;
	val = malloc(lenValue * sizeof(char));
	if (val == NULL)
	{
		perror("failed to allocate value");
		return NULL;
	}
	while (environ[i] != NULL)
	{

		if (strncmp(name, environ[i], lenName) == 0 && strcpy(val, environ[i]))
			return val;

		i++;
	}

	return NULL;
}

char *compose(char *token, char *val)
{
	char *exe;
	int len = strlen(token) + strlen(val) + 1;

	exe = malloc(sizeof(char) * len);

	if (exe == NULL)
		return NULL;

	strcat(exe, val);
	strcat(exe, "/");

	return strcat(exe, token);
}

void search_exe(char **exe)
{
	struct stat statbuf;
	char *exe_path, *path = _getenv("PATH"),
					*value = strtok(path, ":");

	while (value != NULL)
	{
		exe_path = compose(*exe, value);

		if (stat(exe_path, &statbuf) == 0)
		{
			*exe = strdup(exe_path);
			break;
		}

		value = strtok(NULL, ":");
	}
}