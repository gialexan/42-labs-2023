/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/11 21:24:37 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/* Linked List 
void	init_frequency_table(t_frequency *table);
void	fill_frequency_table(t_frequency *table, char *str);
void	frequency_insertion_sort(t_list **list, t_list *node);
void	load_frequency_list(t_frequency *table, t_data *data);

t_list	*newNode(int chr, int event);
void	addFront(t_list *list, t_list *node);
*/


int main(void)
{
	char *tmp = "abcefg";
	t_data		data = {0};
	t_frequency	table[ASCII]; /* Inútil depois de utilizar */
	setlocale(LC_ALL, ""); /* Verificar se tira isso ou não */
	init_frequency_table(table);
	fill_frequency_table(table, tmp); /* Segundo argumento vai ser as linhas do arquivo */
	load_frequency_list(table, &data);

	t_list *test = data.list;
	while (test != NULL)
	{
		printf("CHAR -> %lc | EVENT -> %d\n", test->chr, test->event);
		test = test->next;
	}
	printf("%d\n", data.size);
	return (0);
}
