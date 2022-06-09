/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** bsq
*/

#include "../include/bsq.h"

int get_file_size(const char *filename)
{
    int size = 0;
    struct stat st;

    stat(filename, &st);
    size = st.st_size;
    return (size);
}

static void init_struct(list_info_t *info)
{
    info->result = 0;
    info->x_max = 0;
    info->y_max = 0;
}

static void free_all(list_info_t *info)
{
    for (unsigned int y = info->nbr_row - 1; y != 0; y--)
        free(info->matrix[y]);
    free(info->matrix);
    free(info->buffer);
    free(info);
}

static int bsq(char *filename)
{
    int fd;
    list_info_t *info = malloc(sizeof(list_info_t));

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (84);
    info->buffer = malloc(sizeof(char) * get_file_size(filename) + 1);
    info->buf = malloc(sizeof(char) * get_file_size(filename));
    if (info->buffer == NULL || info->buf == NULL)
        return (84);
    read(fd, info->buffer, get_file_size(filename));
    init_struct(info);
    get_information(info);
    convert_in_matrix(info);
    bigger_square(info);
    print_map(info);
    free_all(info);
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    int value = 0;

    if (ac != 2)
        return (84);
    value = bsq(av[1]);
    return (value);
}
