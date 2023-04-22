#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *allocate(int n);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int num_token(char *str, const char *delim);
void run_non_interactive_mode();
void run_interactive_mode();
void cleanup(char **argv);
void error(char *msg);
void *safe_malloc(size_t size);
char **parse_input(char *input, const char *delim, int *num_tokens);
void execute(char **argv, char **env);
int _putchar(char c);

#endif /* _MAIN__H_ */
