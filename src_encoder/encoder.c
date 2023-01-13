/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 04:24:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/*Fix: Problema na hora de imprimir dictionary */
int main(void)
{
	t_char	tmp[] = "Vamos aprender a programa";
	t_int	table[ASCII];
	t_data	data;
	// char		**dictionary;
	// int			height_tree;

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
	
	/* Passo 4 -> */
	make_dictionary(&data);
	fill_dictionary(data.dictionary, data.list, "", data.height_tree);
	print_dictionary(&data);
	return (0);
}
