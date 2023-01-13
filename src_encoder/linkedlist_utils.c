/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:51:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 03:20:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

t_list *newNode(int chr, int event)
{
	t_list *node = NULL;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->chr = chr;
	node->event = event;
	node->next = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_list *removeFirstNode(t_data *data)
{
	t_list *tmp = NULL;

	if (data->list != NULL)
	{
		tmp = data->list;
		data->list = tmp->next;
		tmp->next = NULL;
		data->size--;
	}
	return (tmp);
}

void	insertion_sort(t_data *data, t_list *node)
{
	t_list *tmp = NULL;

	if (data->list == NULL)
		data->list = node;
	else if (node->event < data->list->event)
		addFront(&data->list, node);
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

void addFront(t_list **list, t_list *node)
{
	node->next = *list;
	*list = node;
}
