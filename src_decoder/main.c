/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:57:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 14:16:41 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	memory_shared(t_memory *memory)
{
	memory->key = key_block(FILENAME);
	memory->id_block = shared_block_id(memory->key);
	memory->map_block = shared_block_map(memory->id_block);
	printf("Reading: %p\n", memory->map_block);
}

int	main(void)
{
	t_int table[256];
	t_memory memory;
	t_data data;

	memory_shared(&memory);
	fill_frequency_table(&memory, table);
	detach_block(memory.map_block);
	build_frequency_list(&data, table);
	build_tree(&data);
	decompress(&data);
}
