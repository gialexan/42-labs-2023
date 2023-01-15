/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:57:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 12:44:55 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

static t_int	bits_is_one(t_char byte, int bit)
{
	t_char mask;

	mask = (1 << bit);
	return (byte & mask);
}

static 	void	write_byte(char c, t_list **tmp, t_data *data)
{
	write(1, &c, 1);
	*tmp = data->list;
}

void	decompress(t_data *data)
{
	t_list *tmp;

	tmp = data->list;
	data->file = fopen("compress.zp", "rb");
	if (!data->file)
		return ;
	while (fread(&data->byte, sizeof(t_char), 1, data->file))
	{
		data->bit = 7;
		while (data->bit >= 0)
		{
			if (bits_is_one(data->byte, data->bit))
				tmp = tmp->right;
			else
				tmp = tmp->left;
			if (is_leaf(tmp->left, tmp->right))
				write_byte(tmp->chr, &tmp, data);
			data->bit--;
		}
	}
	write(1, "\n", 1);
	fclose(data->file);
}
