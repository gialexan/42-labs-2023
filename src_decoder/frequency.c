/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:53:08 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 11:02:48 by coder            ###   ########.fr       */
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
	//data->size = 0;
	data->list = NULL;
	while (i < ASCII)
	{
		if (table[i] > 0)
			insertion_sort(data, new_node(i, table[i]));
		i++;
	}
}