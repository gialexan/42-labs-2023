/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:45:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/11 20:59:50 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define ASCII 256

typedef struct s_frequency
{
	int	chr;
	int	event;
}	t_frequency;

typedef struct s_list
{
	int	chr;
	int	event;
	struct s_list *next;
	struct s_list *left;
	struct s_list *right;
}	t_list;

typedef struct s_data
{
	int		size;
	t_list	*list;
}	t_data;

/* frequency_utils */
void	init_frequency_table(t_frequency *table);
void	fill_frequency_table(t_frequency *table, char *text);
void	load_frequency_list(t_frequency *table, t_data *data);

/* linkedlist_utils */
t_list	*newNode(int chr, int event);
void	addFront(t_list *list, t_list *node);

#endif