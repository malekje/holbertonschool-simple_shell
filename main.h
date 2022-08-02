#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;
char *getln(void);
char **formatln(char *ln);
void launch_process(char **command);
char *compose(char *token, char *val);
void search_exe(char **command);
char *_getenv(char *name);
#endif
