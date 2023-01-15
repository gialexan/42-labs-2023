/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:57:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 13:00:37 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/types.h>
# include <bsd/string.h>

# define ASCII 256
# define BLOCK_SIZE 4096
# define FILENAME "/usr/bin/ls"
# define IPC_RESULT_ERROR (-1)

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

typedef struct s_memory
{
	key_t	key;
	int		id_block;
	t_int	*map_block;
}	t_memory;

typedef struct t_data
{
	int		bit;
	int		height_tree;
	char	*encode_txt;
	char	*decode_txt;
	char	**dictionary;
	FILE	*file;
	t_char	byte;
	t_char	mask;
	t_list	*list;
}	t_data;

/* Prints.c */
void	print_dictionary(t_data *data);
void	print_frequency_list(t_data *data);
void	print_frequency_table(t_int *table);
void	print_encode_decode(char *text, int num);
void	print_tree(t_data *data, t_list *list, int size);

/* Frequency.c */
void	build_frequency_list(t_data *data, t_int *table);
void	build_frequency_table(t_int *table, t_char *text);

/* Linkedlist_utils.c */
t_list	*new_node(int chr, int event);
t_list	*remove_first_node(t_data *data);
void	add_front(t_list **list, t_list *node);

/* Insertion_sort.c */
void	insertion_sort(t_data *data, t_list *node);

/* Tree_utils.c */
void	build_tree(t_data *data);
int		height_tree(t_list *list);
bool 	is_leaf(t_list *left, t_list *right);

/* Dictionary_utils.c */
void	build_dictionary(t_data *data);

/* Encoder.c */
void	encode(t_data *data, t_char *text);

/* Compress.c */
void	compress(t_data *data);


/* Memory.c */
key_t	key_block(char *filename);
int		detach_block(t_int *map_block);
int		shared_block_id(key_t key, int size);
t_int 	*shared_block_map(int id_block);

#endif