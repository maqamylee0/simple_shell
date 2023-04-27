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
void run_non_interactive_mode(int argc, char **argv, char **envp);
void run_interactive_mode(int argc, char **argv, char **envp);
void cleanup(char **argv);
void error(char *msg);
void *safe_malloc(size_t size);
char **parse_input(char *input, const char *delim, int *num_tokens);
void execute(char **argv, char **env);
int _putchar(char c);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void execute_command(char *cmd_path, char **argv, char **env);
char *get_location(char *command);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *s, char c);
int check_argv(char **argv, char **env, char *input, char *input_cpy);
void exit_shell(char **argv, char *input, char *input_cpy);
int _env(char **env);
int _atoi(char *s);
int has_space(char *input);
int _isletter(int c);
#endif /* _MAIN__H_ */
