/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:08:33 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 08:17:54 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	fill_frequency_table(t_memory *memory, t_int *table)
{
	int	i;
	
	i = -1;
	while (++i < ASCII)
		table[i] = memory->map_block[i];
}

void	build_frequency_list(t_data *data, t_int *table)
{
	int	i;

	i = 0;
	data->list = NULL;
	while (i < ASCII)
	{
		if (table[i] > 0)
			insertion_sort(data, new_node(i, table[i]));
		i++;
	}
}