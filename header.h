#ifndef HEADER_H
#define HEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

char **split_string(char *str);
char *_getenv(const char *name);
void path_printer(void);

/**
 * struct list_s - struct for linked list
 * @str: strings that make up the list
 * @next: points to the next node
 *
 * Description: a struct for a singly linked list
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *build_list(char **);
list_t *builde_list(void);
list_t *add_node_end(list_t **head, const char *str);
/*int _setenv(const char *name, const char *value, char **environ);*/
char **split_string(char *);
int _unsetenv(const char *name, char **environ, char *excess, int number);
int open_dir(char *direct, char *name);
char *check_dir(char *, char *);
void free_list(list_t *head);
void _printenv(char **environ);
int _getline(char **buff, int fd);
int get_operator(char **, char **, char *, list_t *);
int _setenv(const char *, const char *, char **, char *);
int _cd(char *directory/*, char **environ*/, char *format);
void free_array(char **);
int no_env(char **environ);
void free_env(char **env, int number);
void exitr(char *, char **, char *, char **, list_t *, int, int);
int readfile(char *file, char *ess, char **env, list_t *h, int num, char *av);
int execute(char *buffer, char **env, int number, list_t *head, char *av);

#endif /*HEADER_H*/
