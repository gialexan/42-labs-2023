/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 10:45:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	memory_shared(t_memory *memory, t_int *table)
{
	memory->key = key_block(FILENAME);
	memory->id_block = shared_block_id(memory->key, BLOCK_SIZE);
	memory->map_block = shared_block_map(memory->id_block);
	printf("Writing: %p\n", memory->map_block);
	memcpy(memory->map_block, table, BLOCK_SIZE);
	detach_block(memory->map_block);
}

/*Fix: Verificar utilizar strlcpy na encode_text e substr no dicionario */
int main(void)
{
	t_char	tmp[] = "Vamos aprender a programação";
	t_int	table[ASCII];
	t_data	data;
	t_memory memory;

	/* Passo 1 -> OK */
	init_frequency_table(table);
	fill_frequency_table(table, tmp);
	print_frequency_table(table);

	/* Passo 2 -> OK */
	make_frequency_list(&data, table);
	print_frequency_list(&data);

	/* Passo 3 -> OK */
	make_huffman_tree(&data);
	print_huffman_tree(&data, data.list, 0);

	/* Passo 4 -> OK */
	make_dictionary(&data);
	fill_dictionary(&data, data.list, "");
	print_dictionary(&data);

	/* Passo 5 -> OK */
	encode_text(&data, tmp);
	print_encode_decode(data.encode_txt, 0);

	/* Passo 7 -> */
	compress(&data);
	memory_shared(&memory, table);

	return (0);
}
