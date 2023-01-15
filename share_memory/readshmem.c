/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readshmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:22:45 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 03:35:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

typedef	unsigned int t_int;
typedef	unsigned char t_char;

typedef struct s_list
{
	t_char			chr;
	int				event;
	struct s_list	*next;
	struct s_list	*left;
	struct s_list	*right;
}	t_list;

typedef struct t_data
{
	int		size;
	int		height_tree;
	char	*encode_txt;
	char	*decode_txt;
	char	**dictionary;
	t_list	*list;
}	t_data;

t_list	*remove_first_node(t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if (data->list != NULL)
	{
		tmp = data->list;
		data->list = tmp->next;
		tmp->next = NULL;
		data->size--;
	}
	return (tmp);
}

void	add_front(t_list **list, t_list *node)
{
	node->next = *list;
	*list = node;
}

t_list	*new_node(int chr, int event)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->chr = chr;
	node->event = event;
	node->next = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	print_frequency_table(t_int *table)
{
	printf("\tfrequency_table:\n");
	for (int i = 0; i < 256; i++) {
		if (table[i] > 0)
			printf("\tDECIMAL: %-3d   |   EVENTS: %-3d   |   CHAR: %-3c\n", i, table[i], i);
	}
	printf("\n");
}

void	insertion_sort(t_data *data, t_list *node)
{
	t_list	*tmp;

	if (data->list == NULL)
		data->list = node;
	else if (node->event < data->list->event)
		add_front(&data->list, node);
	else
	{
		tmp = data->list;
		while (tmp->next != NULL && tmp->next->event <= node->event)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
		tmp = NULL;
	}
	data->size++;
}

void	build_frequency_list(t_data *data, t_int *table)
{
	int	i;

	i = 0;
	data->size = 0;
	data->list = NULL;
	while (i < 256)
	{
		if (table[i] > 0)
			insertion_sort(data, new_node(i, table[i]));
		i++;
	}
}

void	print_frequency_list(t_data *data)
{
	t_list *tmp = data->list;
	printf("\tfrequency_list:\n");
	printf("\tsize: %d\n", data->size);
	while (tmp != NULL)
	{
		printf("\tCHAR: %-3c   |   EVENTS: %-3d\n", tmp->chr, tmp->event);
		tmp = tmp->next;
	}
	printf("\n");
}

static t_list	*new_node_tree(t_list *left_node, t_list *right_node)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->chr = '$';
	node->event = left_node->event + right_node->event;
	node->left = left_node;
	node->right = right_node;
	node->next = NULL;
	return (node);
}

void	build_tree(t_data *data)
{
	t_list	*new_node;
	t_list	*left_node;
	t_list	*right_node;

	new_node = NULL;
	left_node = NULL;
	right_node = NULL;
	if (data->list->next == NULL)
		return ;
	left_node = remove_first_node(data);
	right_node = remove_first_node(data);
	new_node = new_node_tree(left_node, right_node);
	insertion_sort(data, new_node);
	build_tree(data);
}
void	print_huffman_tree(t_data *data, t_list *list, int size)
{
	if (size == 0)
	{
		printf("\thuffman_tree:\n");
		printf("\tsize: %d\n", data->size);
	}
	if (list->right == NULL && list->left == NULL)
		printf("\tLEAF: %-3c   |   Altura: %d\n", list->chr, size);
	else
	{
		print_huffman_tree(data, list->left, size + 1);
		print_huffman_tree(data, list->right, size + 1);
	}
}

int main(void)
{
	key_t	key;
	int		id_block;
	int		*map_block;
	t_data data;
	unsigned int table[256] = {0};
	
	key = key_block(FILENAME);
	id_block = shared_block_id(key, BLOCK_SIZE);
	map_block = shared_block_map(id_block);
	for (int i = 0; i < 256; i++)
	{
		table[i] = map_block[i];
	}
	print_frequency_table(table);
	build_frequency_list(&data, table);
	print_frequency_list(&data);
	build_tree(&data);
	print_huffman_tree(&data, data.list, 0);
	detach_block(map_block);
}