/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:47:42 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 15:39:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	toggle_bits(t_char *byte, int bit)
{
	t_char mask;

	mask = 1;
	mask <<= bit;
	*byte |= mask;
}

static void	save_reset(t_data *data)
{
	fwrite(&data->byte, sizeof(t_char), 1, data->file);
	data->byte = 0;
	data->bit = 7;
}

static void	save_rest(t_data *data)
{
	if (data->bit != 7)
		fwrite(&data->byte, sizeof(t_char), 1, data->file);
}

void	compress(t_data *data)
{
	int	i;

	i = -1;
	data->bit = 7;
	data->byte = 0;
	data->file = fopen("compress.zp", "wb");
	if (!data->file)
		return ;
	while (data->encode_txt[++i] != '\0')
	{
		data->mask = 1;
		if (data->encode_txt[i] == '1') {
			toggle_bits(&data->byte, data->bit);
		}
		data->bit--;
		if (data->bit < 0)
			save_reset(data);
	}
	save_rest(data);
	fclose(data->file);
}
