/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 08:58:27 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/*Fix: Verificar utilizar strlcpy na encode_text e substr no dicionario */
void	memory_shared(t_memory *memory, t_int *table)
{
	memory->key = key_block(FILENAME);
	memory->id_block = shared_block_id(memory->key, BLOCK_SIZE);
	memory->map_block = shared_block_map(memory->id_block);
	printf("Writing: %p\n", memory->map_block);
	memcpy(memory->map_block, table, BLOCK_SIZE);
	detach_block(memory->map_block);
}

static t_int	bits_is_one(t_char byte, int bit)
{
	t_char mask;

	mask = (1 << bit);
	return (byte & mask);
}

void	decompress(t_data *data)
{
	int	bit;
	FILE *file;
	t_char byte;
	t_list *tmp;

	tmp = data->list;
	file = fopen("compress.zp", "rb");
	if (!file)
		return ;
	while (fread(&byte, sizeof(t_char), 1, file))
	{
		bit = 7;
		while (bit >= 0)
		{
			if (bits_is_one(byte, bit))
				tmp = tmp->right;
			else
				tmp = tmp->left;
			if (tmp->right == NULL && tmp->left == NULL)
			{
				printf("%c", tmp->chr);
				tmp = data->list;
			}
			bit--;
		}
	}
	fclose(file);
}

int main(void)
{
	t_char	tmp[] = "oi";
	t_int	table[ASCII];
	t_data	data;
	t_memory memory;

	build_frequency_table(table, tmp);
	//print_frequency_table(table);
	build_frequency_list(&data, table);
	//print_frequency_list(&data);
	build_tree(&data);
	//print_huffman_tree(&data, data.list, 0);
	build_dictionary(&data);
	//print_dictionary(&data);
	encode(&data, tmp);
	// print_encode_decode(data.encode_txt, 0);
	//decode_text(&data, data.encode_txt);
	//print_encode_decode(data.decode_txt, 1);
	compress(&data);
	decompress(&data);
	//memory_shared(&memory, table);
	
	return (0);
}
