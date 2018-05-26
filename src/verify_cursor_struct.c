/*
** EPITECH PROJECT, 2018
** verify_cursor_struct.c
** File description:
** verify if you can move cursor by struct
*/

#include "readline.h"

void print_all_cursor(readline_t *cursor)
{
	while (cursor->prev != NULL)
		cursor = cursor->prev;
	while (cursor->next != NULL) {
		printf("[%c], ", cursor->next->chr);
		cursor = cursor->next;
	}
}

int is_printable_char(int chr)
{
	if (chr != KEY_NULL && chr != KEY_END && chr != KEY_BACK &&
		chr != KEY_TAB && chr != KEY_UP && chr != KEY_DOWN)
		return (1);
	return (0);
}

void print_after_cursor(readline_t *cursor, char *prompt)
{
	write(0, "\033[s\033[K\r", strlen("\033[s\033[K\r"));
	write(0, prompt, strlen(prompt));
	while (cursor->prev != NULL)
		cursor = cursor->prev;
	while (cursor->next != NULL) {
		write(0, &cursor->next->chr, 1);
		cursor = cursor->next;
	}
	write(0, "\033[u", strlen("\033[u"));
}

int can_c_backward(readline_t *cursor)
{
	if (cursor->prev == NULL)
		return (0);
	return (1);
}

int can_c_forward(readline_t *cursor)
{
	if (cursor->next == NULL)
		return (0);
	return (1);
}
