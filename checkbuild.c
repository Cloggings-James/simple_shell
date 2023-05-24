#include <stddef.h>
#include <string.h>
#include "shell.h"


/**
 * checkbuild - Check if a command is a built-in command.
 *
 * @arv: An array of strings representing the command and its arguments.
 *
 * Return: A pointer to the corresponding built-in function if the command is
 *         a built-in, or NULL otherwise.
 */
void (*checkbuild(char **arv))(char **arv)
{
static const struct {
const char *name;
void (*func)(char **arv);
} builtins[] = {
{"exit", exitt},
{"env", env},
{"setenv", _setenv},
{"unsetenv", _unsetenv},
{NULL, NULL}
};

int i;
for (i = 0; builtins[i].name; i++)
{
if (strcmp(arv[0], builtins[i].name) == 0)
{
return (builtins[i].func);
}
}

return (NULL);
}


