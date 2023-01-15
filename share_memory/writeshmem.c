/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeshmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:16:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 03:21:40 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include <stdio.h>

typedef	unsigned int t_int;
typedef	unsigned char t_char;

static void	init_frequency_table(t_int *table)
{
	int	i;

	i = -1;
	while (++i < 256)
		table[i] = 0;
}

void	build_frequency_table(t_int *table, t_char *text)
{
	int		i;
	t_int	chr;

	i = 0;
	init_frequency_table(table);
	while (text[i] != '\0')
	{
		chr = text[i];
		table[chr]++;
		i++;
	}
}

void	print_frequency_table(t_int *table)
{
	printf("\tfrequency_table:\n");
	for (int i = 0; i < 256; i++) {
		if (table[i] > 0)
			printf("\tDECIMAL: %-3d   |   EVENTS: %-3d   |   CHAR: %-3c\n", i, table[i], i);
	}
	printf("\n");
}

int main(void)
{
	key_t	key;
	int		id_block;
	int	*map_block;
	unsigned int table[256];
	unsigned char text[] = "OLA PESSOAL";
	build_frequency_table(table, text);
	print_frequency_table(table);
	
	key = key_block(FILENAME);
	id_block = shared_block_id(key, BLOCK_SIZE);
	map_block = shared_block_map(id_block);
	//printf("Writing: %s\n", text);
	memcpy(map_block, table, BLOCK_SIZE);
	detach_block(map_block);
}