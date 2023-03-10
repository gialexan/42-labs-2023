/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:44:37 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 04:40:01 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	init_frequency_table(t_int *table)
{
	int	i;

	i = -1;
	while (++i < ASCII)
		table[i] = 0;
}

void	build_frequency_table(t_int *table, t_char *text)
{
	int		i;
	t_int	chr;

	i = 0;
	init_frequency_table(table);
	while (text[i] != '\0')
	{
		chr = text[i];
		table[chr]++;
		i++;
	}
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
