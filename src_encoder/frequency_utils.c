/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:44:37 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/12 13:36:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	init_frequency_table(t_frequency *table)
{
	for (int i = 0; i < ASCII; i++) {
		table[i].chr = i;
		table[i].event = 0;
	}
}

void	fill_frequency_table(t_frequency *table, char *text)
{
	int lenght = strlen(text);
	for (int i = 0; i < lenght; i++) {
		table[(unsigned char)text[i]].event++;
	}
}

void	init_frequency_list(t_frequency *table, t_data *data)
{
	for (int i = 0; i < ASCII; i++) {
		if (table[i].event != 0) {
			insertion_sort(&data->list, newNode(table[i].chr, table[i].event));
			data->size++;
		}
	}
}
