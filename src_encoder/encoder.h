/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:45:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 06:06:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <bsd/string.h>
# define ASCII 256

typedef unsigned char	t_char;
typedef unsigned int	t_int;

typedef struct s_list
{
	t_char			chr;
	int				event;
	struct s_list	*next;
	struct s_list	*left;
	struct s_list	*right;
}	t_list;

typedef struct s_data
{
	FILE	*file;
	int		bits;
	int		height_tree;
	char	*encode_txt;
	char	*decode_txt;
	char	**dictionary;
	t_char	byte;
	t_char	mask;
	t_list	*list;
}	t_data;

/* Prints.c */
void	print_dictionary(t_data *data);
void	print_frequency_list(t_data *data);
void	print_frequency_table(t_int *table);
void	print_encode_decode(char *text, int num);
void	print_huffman_tree(t_data *data, t_list *list, int size);

/* Frequency.c */
void	build_frequency_list(t_data *data, t_int *table);
void	build_frequency_table(t_int *table, t_char *text);

/* Linkedlist_utils.c */
t_list	*new_node(int chr, int event);
t_list	*remove_first_node(t_data *data);
void	add_front(t_list **list, t_list *node);
void	insertion_sort(t_data *data, t_list *node);

/* Tree_utils.c */
void	build_tree(t_data *data);
int		height_tree(t_list *list);
t_list	*newNodeTree(t_list *left_node, t_list *right_node);

/* Dictionary_utils.c */
void	build_dictionary(t_data *data);

/* Encoder.c */
void	encode(t_data *data, t_char *text);

/* Compress.c */
void	compress(t_data *data);

#endif