/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:04:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 08:56:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void toggle_bits(t_char *byte, int bits)
{
	t_char mask;

	mask = 1;
	mask <<= bits;
	*byte |= mask;
}

static void	save_reset(t_data *data)
{
	fwrite(&data->byte, sizeof(t_char), 1, data->file);
	data->byte = 0;
	data->bits = 7;
}

void	compress(t_data *data)
{
	int	i;
	i = -1;
	data->bits = 7;
	data->file = fopen("compress.zp", "wb");
	if (!data->file)
		return ;
	while (data->encode_txt[++i] != '\0')
	{
		data->mask = 1;
		if (data->encode_txt[i] == '1')
			toggle_bits(&data->byte, data->bits);
		data->bits--;
		if (data->bits < 0) {
			save_reset(data);
		}
	}
	if (data->bits != 7)
		save_reset(data);
	fclose(data->file);
}
