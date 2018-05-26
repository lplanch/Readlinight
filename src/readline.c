/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** 2nd try
*/

#include "readline.h"

int verify_key(char chr)
{
	if (chr == KEY_ENTER)
		return (1);
	if (chr == KEY_RIGHT)
		C_FORWARD;
	else if (chr == KEY_LEFT)
		C_BACKWARD;
	else
		putchar(chr);
	return (0);
}

char *readline(char *prompt)
{
	readline_t *cursor = NULL;
	int chr;

        while (1) {
        	chr = get_key();
		if (verify_key(chr))
			break;
	}
        printf("\n");
        return 0;
}
