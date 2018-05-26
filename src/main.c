/*
** EPITECH PROJECT, 2018
** main.c
** File description:
**
*/

#include "readline.h"

int main(void)
{
	char *test = NULL;

	while ((test = readline("$> ")) != NULL)
		printf("\nline : [%s]\n", test);
	return (0);
}
