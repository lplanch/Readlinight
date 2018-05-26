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

	while (1) {
		test = readline("$> ");
		printf("\nline : %s\n", test);
	}
	return (0);
}
