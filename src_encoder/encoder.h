/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:45:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/12 14:50:39 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/types.h>

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

/* Frequency_utils.c */
void	init_frequency_table(t_frequency *table);
void	fill_frequency_table(t_frequency *table, char *text);
void	init_frequency_list(t_frequency *table, t_data *data);

/* Linkedlist_utils.c */
t_list	*newNode(int chr, int event);
t_list	*removeFirstNode(t_data *data);
void	addFront(t_list **list, t_list *node);
void	insertion_sort(t_list **list, t_list *node);

/* Tree_utils.c */
void	make_huffman_tree(t_data *data);
t_list	*newNodeTree(t_list *left_node, t_list *right_node);

#endif