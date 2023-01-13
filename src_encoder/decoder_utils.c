/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:18:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 08:19:33 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	decode_text(t_data *data, char *text)
{
	int	i;
	char c;
	t_list *tmp;

	i = -1;
	tmp = data->list;
	data->decode_txt = calloc(strlen(text), sizeof(char));
	while(text[++i] != '\0')
	{
		if (text[i] == '0')
			tmp = tmp->left;
		else
			tmp = tmp->right;
		if (tmp->left == NULL && tmp->right == NULL)
		{
			c = tmp->chr;
			strncat(data->decode_txt, &c, 1);
			tmp = data->list;
		}
	}
}