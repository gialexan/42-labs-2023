/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:57:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 14:20:25 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	memory_shared(t_memory *memory, t_int *table)
{
	memory->key = key_block(FILENAME);
	memory->id_block = shared_block_id(memory->key);
	memory->map_block = shared_block_map(memory->id_block);
	printf("Writing: %p\n", memory->map_block);
	memcpy(memory->map_block, table, BLOCK_SIZE);
	detach_block(memory->map_block);
}

int main(void)
{
	t_char	tmp[] = "Vamos aprender a programação";
	t_int	table[ASCII];
	t_data	data;
	t_memory memory;

	build_frequency_table(table, tmp);
	build_frequency_list(&data, table);;
	build_tree(&data);
	build_dictionary(&data);
	encode(&data, tmp);
	compress(&data);
	memory_shared(&memory, table);
	return (0);
}
