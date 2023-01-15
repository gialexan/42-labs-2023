/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:42:18 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 11:22:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_int	bits_is_one(t_char byte, int bit)
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
