/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:54:14 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 11:23:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_list	*new_node_tree(t_list *left_node, t_list *right_node)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->chr = '$';
	node->event = left_node->event + right_node->event;
	node->left = left_node;
	node->right = right_node;
	node->next = NULL;
	return (node);
}

void	build_tree(t_data *data)
{
	t_list	*new_node;
	t_list	*left_node;
	t_list	*right_node;

	new_node = NULL;
	left_node = NULL;
	right_node = NULL;
	if (data->list->next == NULL)
		return ;
	left_node = remove_first_node(data);
	right_node = remove_first_node(data);
	new_node = new_node_tree(left_node, right_node);
	insertion_sort(data, new_node);
	build_tree(data);
}