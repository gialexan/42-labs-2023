/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:45:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/13 05:33:38 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define ASCII 256

typedef unsigned char	t_char;
typedef	unsigned int	t_int;

typedef struct s_list
{
	t_char	chr;
	int	event;
	struct s_list *next;
	struct s_list *left;
	struct s_list *right;
}	t_list;

typedef struct t_data
{
	int		size;
	int		height_tree;
	char	**dictionary;
	t_list *list;
}	t_data;

/* Prints.c */
void	print_dictionary(t_data *data);
void	print_frequency_list(t_data *data);
void	print_frequency_table(t_int *table);
void	print_huffman_tree(t_data *data, t_list *list, int size);

/* Frequency_utils.c */
void	init_frequency_table(t_int *table);
void	make_frequency_list(t_data *data, t_int *table);
void	fill_frequency_table(t_int *table, t_char *text);

/* Linkedlist_utils.c */
t_list	*newNode(int chr, int event);
t_list	*removeFirstNode(t_data *data);
void	addFront(t_list **list, t_list *node);
void	insertion_sort(t_data *data, t_list *node);

/* Tree_utils.c */
void	make_huffman_tree(t_data *data);
int		height_huffman_tree(t_list *list);
t_list	*newNodeTree(t_list *left_node, t_list *right_node);

/* Dictionary_utils.c */
void	make_dictionary(t_data *data);
void	fill_dictionary(t_data *data, t_list *list, char *path, int height_tree);

#endif