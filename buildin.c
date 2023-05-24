#include "shell.h"

/**
 * exitt - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void exitt(char **arv)
{
	int n = 0;

	if (arv[1])
		n = _atoi(arv[1]);
	freearv(arv);
	exit(n);
}

/**
 * _atoi - converts a string into an integer
 * @s: pointer to a string
 * Return: the integer
 */

int _atoi(char *s)
{
	int integer = 0;
	int sign = 1;

	while (*s)
{
	if (*s == '-')
		sign = -sign;
	else if (*s >= '0' && *s <= '9')
		integer = integer * 10 + (*s - '0');
	else if (integer > 0)
		break;
	s++;
}

return (sign * integer);

}

/**
 * env - prints the current environment
 * @arv: array of arguments
 */

void env(char **arv __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arv: array of entered words
 */

void _setenv(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = concat_all(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';
	}
}

/**
 * _unsetenv - Remove an environment variable
 * @arv: array of entered words
 */
void _unsetenv(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(arv[1], environ[i], strlen(arv[1])) == 0)
		{
			free(environ[i]);
			for (j = i; environ[j + 1]; j++)
				environ[j] = environ[j + 1];
			environ[j] = NULL;
			return;
		}
	}
