/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/12 10:31:33 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

int main(void)
{				/* a = 3 | b = 4 | c = 2 | d = 1 | 5 = f | aaabbbbccdfffff*/
	char *tmp = "aaabbbbccdfffff";
	t_data		data = {0};
	t_frequency	table[ASCII]; 	/* Inútil depois de utilizar */
	setlocale(LC_ALL, ""); 		/* Verificar se vai ser útil deixar isso */
	init_frequency_table(table);
	fill_frequency_table(table, tmp); /* Segundo argumento vai ser as linhas do arquivo */
	load_frequency_list(table, &data);
	

	// t_list *test = data.list;
	// while (test != NULL)
	// {
	// 	printf("CHAR -> %c | EVENT -> %d\n", test->chr, test->event);
	// 	test = test->next;
	// }
	return (0);
}
