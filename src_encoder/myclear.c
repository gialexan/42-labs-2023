/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myclear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:29:40 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 15:52:04 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	clear_tree(t_list *list)
{
	if (list == NULL)
    	return;

  	clear_tree(list->left);
  	clear_tree(list->right);
  	free(list);
  	list = NULL;
}

static void	clear_dictionary(char **dictionary)
{
	int	i;

	i = -1;
	while(++i < ASCII)
		free(dictionary[i]);
	free(dictionary);
	dictionary = NULL;
}

static void	clear_encode_txt(char *encode_txt)
{
	free(encode_txt);
	encode_txt = NULL;
}

void	myclear(t_data *data)
{
	clear_dictionary(data->dictionary);
	clear_encode_txt(data->encode_txt);
	clear_tree(data->list);
}