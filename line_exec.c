#include "shell.h"


/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **splitstring(char *str, const char *delim)
{
int i, wn;
char **array;
char *token;
char *copy;

copy = malloc(_strlen(str) + 1);
if (copy == NULL)
{
perror(_getenv("_"));
return (NULL);
}
i = 0;
while (str[i])
{
copy[i] = str[i];
i++;
}
copy[i] = '\0';
token = strtok(copy, delim);
array = malloc((sizeof(char *) * 2));
array[0] = _strdup(token);

i = 1;
wn = 3;
while (token)
{
token = strtok(NULL, delim);
array = _realloc(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
array[i] = _strdup(token);
i++;
wn++;
}
free(copy);
return (array);
}

/**
 * execute - executes a command
 *
 * @argv: An array of arguments.
 */
void execute(char **argv)
{
int pid, status;

if (argv == NULL || argv[0] == NULL)
return;

pid = fork();
if (pid < 0)
{
perror("_getenv");
return;
}

if (pid == 0)
{
if (execve(argv[0], argv, environ) == -1)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
}
else
{
if (wait(&status) == -1)
{
perror("wait");
}
}
}

/**
 * _realloc - Reallocates memory block
 *
 * @ptr: A pointer to the memory block to be reallocated.
 * @old_size: The size of the original memory block.
 * @new_size: The new size of the memory block.
 *
 * Return: A pointer to the reallocated memory block, or NULL if the
 *         reallocation failed.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr = NULL;
char *old_ptr = ptr;
unsigned int i;

if (new_size == old_size)
return (ptr);

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

if (ptr == NULL)
return (new_ptr);

if (new_size > old_size)
{
for (i = 0; i < old_size; i++)
new_ptr[i] = old_ptr[i];
for (i = old_size; i < new_size; i++)
new_ptr[i] = '\0';
}
else
{
for (i = 0; i < new_size; i++)

;
}


free(ptr);
return (new_ptr);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */

void freearv(char **arv)
{
int i;

for (i = 0; arv[i]; i++)
free(arv[i]);
free(arv);
}
