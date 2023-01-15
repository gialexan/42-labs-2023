/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:32:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 16:46:49 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

FILE    *get_file(char *filename, char *mode_open)
{
    FILE    *file;
	
	file = fopen(filename, mode_open);
    if (!file)
        perror("");
    return (file);
}

static int size_file(char *filename)
{
    FILE    *file;
    int     count;
    
    file = get_file(filename, "r");
    count = 0;
    while (fgetc(file) != -1)
        count++;
    fclose(file);
    return (count);
}

static void	load_file(char *filename, unsigned char *s)
{
    int     i;
    FILE    *file;
    char    character;

    i = 0;
    file = get_file(filename, "r");
    while (!feof(file))
    {
        character = fgetc(file);
        if (character != -1)
            s[i] = character;
        i++;
    }
    fclose(file);
}

t_char   *get_text(char **argv)
{
	int		size;
    t_char	*text;

    size = size_file(argv[1]);
    text = calloc(size + 1, sizeof(char));
    load_file(argv[1], text);
    return (text);
}