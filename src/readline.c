/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** 2nd try
*/

#include "readline.h"

int verify_key(int chr, readline_t **cursor)
{
	if (chr == KEY_ENTER || chr == KEY_END)
		return (0);
	if (chr == KEY_BACK && can_c_backward(*cursor)) {
		write(0, "\b", 1);
		return (2);
	}
	if (chr == KEY_LEFT && can_c_backward(*cursor)) {
		(*cursor) = (*cursor)->prev;
		C_BACKWARD;
	} else if (chr == KEY_RIGHT && can_c_forward(*cursor)) {
		(*cursor) = (*cursor)->next;
		C_FORWARD;
	} else {
		if (chr != KEY_RIGHT && chr != KEY_LEFT) {
			add_chr_cursor(cursor, chr);
			C_FORWARD;
			return (2);
		}
	}
	return (1);
}

char *readline(char *prompt)
{
	readline_t *cursor = create_chr_cursor(0, NULL, NULL);
	int chr;
	int value;

	write(1, prompt, strlen(prompt));
        while (1) {
        	chr = get_key();
		value = verify_key(chr, &cursor);
		if (value == 0)
			break;
		print_after_cursor(cursor, prompt);
	}
	if (chr == KEY_END)
		return (NULL);
        return ("ok");
}
