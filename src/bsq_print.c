/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** bsq_struct
*/

#include "../include/bsq.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

void print_map_next(list_info_t *info)
{
    int begin;
    int x = 0;

    for (begin = 0; info->buffer[begin] != '\n'; begin++);
    for (unsigned int p = begin + 1; info->buffer[p] != '\0'; p++)
        info->buf[x++] = info->buffer[p];
}

void print_map(list_info_t *info)
{
    int pos_x = 0;
    int pos_y = 0;
    int start_y = info->y_max - (info->result - 1);
    int start_x = info->x_max - (info->result - 1);

    print_map_next(info);
    for (unsigned int p = 0; info->buf[p] != '\0'; p++) {
        if (pos_y >= start_y && pos_y <= info->y_max) {
            if (pos_x >= start_x && pos_x <= info->x_max)
                info->buf[p] = 'x';
        }
        pos_x++;
        if (info->buf[p] == '\n') {
            pos_y++;
            pos_x = 0;
        }
    }
    write(1, info->buf, my_strlen(info->buf));
}
