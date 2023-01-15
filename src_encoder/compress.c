/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:44:10 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 11:23:40 by coder            ###   ########.fr       */
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

void	compress(t_data *data)
{
	int	i;
	int	bit;
	FILE *file;
	t_char byte;
	t_char mask;

	i = -1;
	bit = 7;
	file = fopen("compress.zp", "wb");
	if (!file)
		return ;
	while (data->encode_txt[++i] != '\0')
	{
		mask = 1;
		if (data->encode_txt[i] == '1') {
			toggle_bits(&byte, bit);
		}
		bit--;
		if (bit < 0)
		{
			fwrite(&byte, sizeof(t_char), 1, file);
			byte = 0;
			bit = 7;
		}
	}
	if (bit != 7)
		fwrite(&byte, sizeof(t_char), 1, file);
	fclose(file);
}
