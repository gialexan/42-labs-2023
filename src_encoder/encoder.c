/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 20:26:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	toggle_bits(t_char *byte, int bit)
{
	t_char mask;

	mask = 1;
	mask <<= bit;
	*byte |= mask;
}

t_int	bits_is_one(t_char byte, int bit)
{
	t_char mask;

	mask = (1 << bit);
	return (byte & mask);
}

void	compress(t_data *data)
{
	int	i;
	int	bit;
	FILE *file;
	t_char byte;
	t_char mask;

	i = -1;
	bit = 7;
	file = fopen("compress.zp", "wb");
	if (!file)
		return ;
	while (data->encode_txt[++i] != '\0')
	{
		mask = 1;
		if (data->encode_txt[i] == '1') {
			toggle_bits(&byte, bit);
		}
		bit--;
		if (bit < 0)
		{
			fwrite(&byte, sizeof(t_char), 1, file);
			byte = 0;
			bit = 7;
		}
	}
	if (bit != 7)
		fwrite(&byte, sizeof(t_char), 1, file);
	fclose(file);
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

/*Fix: Verificar utilizar strlcpy na encode_text e substr no dicionario */
int main(void)
{
	t_char	tmp[] = "Vamos aprender a programação";
	t_int	table[ASCII];
	t_data	data;

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

	/* Passo 6 -> OK */
	decode_text(&data, data.encode_txt);
	print_encode_decode(data.decode_txt, 1);

	/* Passo 7 -> */
	compress(&data);
	printf("\tdecode archive:\n");
	printf("\t\t");
	decompress(&data);
	printf("\n");

	return (0);
}
