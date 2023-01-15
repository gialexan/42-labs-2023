/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:57:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 14:23:08 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	insertion_sort(t_data *data, t_list *node)
{
	t_list	*tmp;

	if (data->list == NULL)
		data->list = node;
	else if (node->event < data->list->event)
		add_front(&data->list, node);
	else
	{
		tmp = data->list;
		while (tmp->next != NULL && tmp->next->event <= node->event)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
		tmp = NULL;
	}
}
