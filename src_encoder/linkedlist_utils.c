/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:51:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/11 22:32:23 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

t_list *newNode(int chr, int event)
{
	t_list *node;

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

void addFront(t_list **list, t_list *node)
{
	node->next = *list;
	*list = node;
}