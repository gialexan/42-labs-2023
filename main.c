/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/11 18:49:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define ASCII 256

typedef struct s_frequency
{
	int	chr;
	int	event;
	struct s_frequency *next;
}	t_frequency;

void		init_frequency_table(t_frequency *table);
void		fill_frequency_table(t_frequency *table, char *str);
void		frequency_insertion_sort(t_frequency **list, t_frequency *node);
t_frequency	*load_frequency_list(t_frequency *table);

/* Linked List */
t_frequency	*newNode(int chr, int event);
void		addFront(t_frequency *stack, t_frequency *node);


int main(void)
{
	char *tmp = "OAAABBBBCDDEEEEEEFFFFGGGGGGGGGGH";
	t_frequency *list;
	t_frequency	table[ASCII];
	setlocale(LC_ALL, "");
	init_frequency_table(table);
	fill_frequency_table(table, tmp);
	list = load_frequency_list(table);

	t_frequency *tmp1 = list;
	
	while(tmp1->next)
	{
		printf("CHARACTER %lc  -  EVENTS: %d\n", tmp1->chr, tmp1->event);
		tmp1 = tmp1->next;
	}
	return (0);
}

void	init_frequency_table(t_frequency *table)
{
	for(int i = 0; i < ASCII; i++) {
		table[i].chr = i;
		table[i].event = 0;
		table[i].next = NULL;
	}
}

void	fill_frequency_table(t_frequency *table, char *text)
{
	for (int i = 0; i < strlen(text); i++) {
		table[text[i]].event++;
	}
}

void	frequency_insertion_sort(t_frequency **list, t_frequency *node)
{
	t_frequency *tmp;

	if (*list == NULL)
		*list = node;
	else if (node->event < (*list)->event)
		addFront(*list, node);
	else
	{
		tmp = *list;
		while (tmp->next && tmp->next->event <= node->event)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;	
	}
}

t_frequency	*load_frequency_list(t_frequency *table)
{
	t_frequency	*list = NULL;

	for (int i = 0; i < ASCII; i++) {
		if (table[i].event != 0)
			frequency_insertion_sort(&list, newNode(table[i].chr, table[i].event));
	}
	return (list);
}

/* Linked List */
t_frequency *newNode(int chr, int event)
{
	t_frequency *node;

	node = malloc(sizeof(t_frequency));
	if (!node)
		return (NULL);
	node->chr = chr;
	node->event = event;
	node->next = NULL;
	return (node);
}

void addFront(t_frequency *stack, t_frequency *node)
{
	node->next = stack;
	stack = node;
}
