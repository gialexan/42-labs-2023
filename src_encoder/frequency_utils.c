/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:44:37 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/11 20:49:32 by gialexan         ###   ########.fr       */
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
	for (int i = 0; i < strlen(text); i++) {
		table[text[i]].event++;
	}
}

static	void	frequency_insertion_sort(t_list **list, t_list *node)
{
	t_list *tmp;

	if (*list == NULL)
		*list = node;
	else if (node->event < (*list)->event)
		addFront(*list, node);
	else
	{
		tmp = *list;
		while (tmp->next && tmp->next->event <= node->event)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
	}
}

void	load_frequency_list(t_frequency *table, t_data *data)
{
	for (int i = 0; i < ASCII; i++) {
		if (table[i].event != 0) {
			frequency_insertion_sort(&data->list, newNode(table[i].chr, table[i].event));
			data->size++;
		}
	}
}
