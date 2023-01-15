/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:32:25 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 08:49:55 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	print_huffman_tree(t_data *data, t_list *list, int size)
{
	if (size == 0)
		printf("\thuffman_tree:\n");
	if (list->right == NULL && list->left == NULL)
		printf("\tLEAF: %-3c   |   Altura: %d\n", list->chr, size);
	else
	{
		print_huffman_tree(data, list->left, size + 1);
		print_huffman_tree(data, list->right, size + 1);
	}
}

void	memory_shared(t_memory *memory)
{
	memory->key = key_block(FILENAME);
	memory->id_block = shared_block_id(memory->key, BLOCK_SIZE);
	memory->map_block = shared_block_map(memory->id_block);
	printf("Reading: %p\n", memory->map_block);
}

int main(void)
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
	printf("\n");
}