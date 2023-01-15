/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 05:46:53 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/*Fix: Verificar utilizar strlcpy na encode_text e substr no dicionario */

int main(void)
{
	t_char	tmp[] = "Vamos aprender a programação";
	t_int	table[ASCII];
	t_data	data;

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
	return (0);
}
