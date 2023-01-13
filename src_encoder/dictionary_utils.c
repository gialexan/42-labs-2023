/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 05:34:33 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (0);
	if (strlen(s) < start)
		len = 0;
	if (strlen(s + start) < len)
		len = strlen(s + start);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

void	fill_dictionary(t_data *data, t_list *list, char *path, int height_tree)
{
	char left[height_tree];
	char right[height_tree];

	if (list->left == NULL && list->right == NULL) {
		strncpy(data->dictionary[list->chr], path, height_tree);
		//data->dictionary[list->chr] = ft_substr(path, 0, strlen(path));
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
	data->height_tree = height_huffman_tree(data->list) + 1;
	data->dictionary = malloc(ASCII * sizeof(char *));
	while (++i < ASCII)
		data->dictionary[i] = calloc(data->height_tree, sizeof(char));
}