/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 08:21:32 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/*Fix: Verificar utilizar strlcpy na encode_text e substr no dicionario */
int main(void)
{
	t_char	tmp[] = "Vamos aprender a programar";
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

	/* Passo 5 -> OK*/
	encode_text(&data, tmp);
	print_encode_decode(data.encode_txt, 0);

	/* Passo 6 -> */
	decode_text(&data, data.encode_txt);
	print_encode_decode(data.decode_txt, 1);
	
	return (0);
}
