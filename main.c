/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:50:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/11 14:25:25 by gialexan         ###   ########.fr       */
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
}	t_frequency;

void	init_frequency_table(t_frequency *table);
void	fill_frequency_table(t_frequency *table, char *str);


int main(void)
{
	setlocale(LC_ALL, "");
	char *tmp = "Ola 42 Sp";
	t_frequency	table[ASCII];
	init_frequency_table(table);
	fill_frequency_table(table, tmp);

	// for (int i = 0; i < ASCII; i++) {
	// 	printf("ASCII: (%lc)   | EVENTS: (%d)\n",table[i].chr, table[i].event);
	// }
}

void	init_frequency_table(t_frequency *table)
{
	for(int i = 0; i < ASCII; i++) {
		table[i].chr = i;
		table[i].event = 0;
	}
}

void	fill_frequency_table(t_frequency *table, char *text)
{
	for (int i = 0; i < strlen(text); i++) {
		table[(unsigned char)text[i]].event++;
	}
}