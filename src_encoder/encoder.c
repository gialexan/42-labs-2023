/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 06:41:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

int	size_encode(t_data *data, t_char *text)
{
	int	i;
	int size;

	i = -1;
	size = 0;
	while (text[++i] != '\0')
		size += strlen(data->dictionary[text[i]]);
	return (size + 1);
}

void	encode_text(t_data *data, t_char *text)
{
	int	i;

	i = -1;
	data->size = size_encode(data, text);
	data->encode_txt = malloc(data->size * sizeof(char));
	while (text[++i] != '\0')
		strncat(data->encode_txt, data->dictionary[text[i]], data->height_tree);
}
/*Fix: Verificar utilizar strlcpy na encode_text e substr no dicionario */
int main(void)
{
	t_char	tmp[] = "Vamos aprender a programa";
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
	fill_dictionary(&data, data.list, "", data.height_tree);
	print_dictionary(&data);
	
	/* Passo 5 -> OK*/
	encode_text(&data, tmp);
	print_encode(&data);
	return (0);
}
