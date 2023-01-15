/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:05:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 08:33:40 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

static t_int	bits_is_one(t_char byte, int bit)
{
	t_char mask;

	mask = (1 << bit);
	return (byte & mask);
}

void	decompress(t_data *data)
{
	int	bit;
	FILE *file;
	t_char byte;
	t_list *tmp;

	tmp = data->list;
	file = fopen("compress.zp", "rb");
	if (!file)
		return ;
	while (fread(&byte, sizeof(t_char), 1, file))
	{
		bit = 7;
		while (bit >= 0)
		{
			if (bits_is_one(byte, bit))
				tmp = tmp->right;
			else
				tmp = tmp->left;
			if (tmp->right == NULL && tmp->left == NULL)
			{
				printf("%c", tmp->chr);
				tmp = data->list;
			}
			bit--;
		}
	}
	fclose(file);
}
