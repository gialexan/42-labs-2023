/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 07:15:48 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

//data->dictionary[list->chr] = ft_substr(path, 0, strlen(path));
void	fill_dictionary(t_data *data, t_list *list, char *path)
{
	char	left[data->height_tree];
	char	right[data->height_tree];

	if (list->left == NULL && list->right == NULL)
		strncpy(data->dictionary[list->chr], path, data->height_tree);
	else
	{
		strncpy(left, path, data->height_tree);
		strncpy(right, path, data->height_tree);

		strncat(left, "0", data->height_tree);
		strncat(right, "1", data->height_tree);

		fill_dictionary(data, list->left, left);
		fill_dictionary(data, list->right, right);
	}
}

//Otimizar: Talvez usar substr
void	make_dictionary(t_data *data)
{
	int	i;

	i = -1;
	data->height_tree = height_huffman_tree(data->list) + 1;
	data->dictionary = malloc(ASCII * sizeof(char *));
	while (++i < ASCII)
		data->dictionary[i] = calloc(data->height_tree, sizeof(char));
}
