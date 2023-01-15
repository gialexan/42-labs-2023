/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:36:54 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 10:37:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

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
	data->size++;
}