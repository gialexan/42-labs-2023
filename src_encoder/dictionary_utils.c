/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 04:15:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	fill_dictionary(char **data, t_list *list, char *path, int height_tree)
{
	char left[height_tree];
	char right[height_tree];

	if (list->left == NULL && list->right == NULL) {
		strncpy(data[list->chr], path, height_tree);
		//dictionary[list->chr] = strstr(path, path);
	}
	else
	{
		strncpy(left, path, height_tree);
		strncpy(right, path, height_tree);

		strncat(left, "0", height_tree);
		strncat(right, "1", height_tree);

		fill_dictionary(data, list->left, left, height_tree);
		fill_dictionary(data, list->right, right, height_tree);
	}
}

//Otimizar: Talvez usar substr
void	make_dictionary(t_data *data)
{
	int	i;

	i = -1;
	data->height_tree = height_huffman_tree(data->list);
	data->dictionary = malloc(ASCII * sizeof(char));
	while (++i < ASCII)
		data->dictionary[i] = calloc(data->height_tree, sizeof(char));
}