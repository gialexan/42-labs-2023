/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:57:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 12:03:17 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_list	*new_node(int chr, int event)
{
	t_list	*node;

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

t_list	*remove_first_node(t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if (data->list != NULL)
	{
		tmp = data->list;
		data->list = tmp->next;
		tmp->next = NULL;
	}
	return (tmp);
}

void	add_front(t_list **list, t_list *node)
{
	node->next = *list;
	*list = node;
}