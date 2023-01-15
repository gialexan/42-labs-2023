/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:47:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 07:12:47 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

int	height_huffman_tree(t_list *list)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	if (list == NULL)
		return (-1);
	else
	{
		left = height_huffman_tree(list->left) + 1;
		right = height_huffman_tree(list->right) + 1;
		if (left > right)
			return (left);
		else
			return (right);
	}
}

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

void	make_huffman_tree(t_data *data)
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
	make_huffman_tree(data);
}
