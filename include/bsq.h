/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct list_info
{
    char *buffer;
    int nbr_col;
    int nbr_row;
    int **matrix;
    int result;
    int x_max;
    int y_max;
    char *buf;
} list_info_t;

void bigger_square(list_info_t *info);
void convert_in_matrix(list_info_t *info);
void get_information(list_info_t *info);
void print_map(list_info_t *info);

#endif /* !BSQ_H_ */
