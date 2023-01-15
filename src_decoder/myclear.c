/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myclear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:29:40 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 15:54:10 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

static void	clear_tree(t_list *list)
{
	if (list == NULL)
    	return;

  	clear_tree(list->left);
  	clear_tree(list->right);
  	free(list);
  	list = NULL;
}

void	myclear(t_data *data)
{
	clear_tree(data->list);
}