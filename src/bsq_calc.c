/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** bsq
*/

#include "../include/bsq.h"

static int calc_square(int pos1, int pos2, int pos3)
{
    int tab[3] = {pos1, pos2, pos3};

    for (unsigned int i = 0; i < 3; i++) {
        if (tab[0] > tab[i])
            tab[0] = tab[i];
    }
    return (tab[0] + 1);
}

static void bigger_square_next(list_info_t *info, int x, int y)
{
    if (info->result < info->matrix[y][x]) {
        info->result = info->matrix[y][x];
        info->y_max = y;
        info->x_max = x;
    }
}

void bigger_square(list_info_t *info)
{
    for (unsigned int y = 1; info->matrix[y] != NULL; y++) {
        for (unsigned int x = 1; x != info->nbr_col; x++) {
            if (info->matrix[y][x] == 0)
                ++x;
            else {
                info->matrix[y][x] = calc_square(info->matrix[y][x - 1],
                    info->matrix[y - 1][x - 1], info->matrix[y - 1][x]);
                bigger_square_next(info, x, y);
            }
            if (x == info->nbr_col) {
                break;
            }
        }
    }
}

void convert_in_matrix(list_info_t *info)
{
    int begin;
    int x = 0;
    int y = 0;

    for (begin = 0; info->buffer[begin] != '\n'; begin++);
    info->matrix = malloc(sizeof(int *) * info->nbr_row + 1);
    info->matrix[0] = malloc(sizeof(int) * info->nbr_col + 1);
    for (unsigned int i = begin + 1; info->buffer[i] != '\0'; i++) {
        if (info->buffer[i] == '.')
            info->matrix[y][x] = 1;
        if (info->buffer[i] == 'o')
            info->matrix[y][x] = 0;
        x++;
        if (info->buffer[i] == '\n') {
            info->matrix[++y] = malloc(sizeof(int) * info->nbr_col + 1);
            x = 0;
        }
    }
    info->matrix[info->nbr_row] = NULL;
}

void get_information(list_info_t *info)
{
    int begin;

    info->nbr_row = 0;
    info->nbr_col = 0;
    for (begin = 0; info->buffer[begin] != '\n'; begin++);
    for (int i = begin + 1; info->buffer[i] != '\0'; i++)
        if (info->buffer[i] == '\n')
            info->nbr_row++;
    for (int i = begin + 1; info->buffer[i] != '\n'; i++)
        info->nbr_col++;
}
