/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:59:19 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 14:20:38 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	print_frequency_list(t_data *data)
{
	t_list *tmp = data->list;
	printf("\tfrequency_list:\n");
	while (tmp != NULL)
	{
		printf("\tCHAR: %-3c   |   EVENTS: %-3d\n", tmp->chr, tmp->event);
		tmp = tmp->next;
	}
	printf("\n");
}

void	print_frequency_table(t_int *table)
{
	printf("\tfrequency_table:\n");
	for (int i = 0; i < ASCII; i++) {
		if (table[i] > 0)
			printf("\tDECIMAL: %-3d   |   EVENTS: %-3d   |   CHAR: %-3c\n", i, table[i], i);
	}
	printf("\n");
}

void	print_tree(t_data *data, t_list *list, int size)
{
	if (size == 0)
		printf("\thuffman_tree:\n");
	if (is_leaf(list->left, list->right))
		printf("\tLEAF: %-3c   |   Altura: %d\n", list->chr, size);
	else
	{
		print_tree(data, list->left, size + 1);
		print_tree(data, list->right, size + 1);
	}
}

void	print_dictionary(t_data *data)
{
	printf("\n\tprint_dictionary:\n");
	for (int i = 0; i < ASCII; i++) {
		if (strlen(data->dictionary[i]) > 0)
			printf("\tINT: %-3d    |   CHAR: %-3lc   |   DIC: %-3s\n", i, i, data->dictionary[i]);
	}
	printf("\n");
}

void	print_encode_decode(char *text, int num)
{
	if (num == 0)
	{
		printf("\tencode text:\n");
		printf("\t\t%s\n", text);
	}
	else
	{
		printf("\tdecode text:\n");
		printf("\t\t%s\n", text);
	}
}
