/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** .h file to stock all functions from get_next_line
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#ifndef READLINE_H
#	define READLINE_H

#define C_FORWARD write(1, "\033[1D", 5)
#define C_BACKWARD write(1, "\033[1C", 5)

#define KEY_ESCAPE	27
#define KEY_ENTER	10
#define KEY_UP		0x0105
#define KEY_DOWN	0x0106
#define KEY_LEFT	68
#define KEY_RIGHT	67

typedef struct readline
{
	char chr;
	struct readline *next;
} readline_t;

char *readline(char *prompt);
int get_key(void);

#endif
