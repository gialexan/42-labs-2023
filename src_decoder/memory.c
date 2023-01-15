/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:52:17 by coder             #+#    #+#             */
/*   Updated: 2023/01/15 11:23:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

key_t	key_block(char *filename)
{
	key_t key;
	
	key = ftok(filename, 0);
	if (key == IPC_RESULT_ERROR)
		return (IPC_RESULT_ERROR);
	return (key);
}

int	shared_block_id(key_t key, int size)
{
	int	id_block;

	id_block = shmget(key, BLOCK_SIZE, 0644 | IPC_CREAT);
	if(id_block == IPC_RESULT_ERROR)
		return (IPC_RESULT_ERROR);
	return (id_block);
}

t_int *shared_block_map(int id_block)
{
	t_int *map_block;

	map_block = (t_int*)shmat(id_block, NULL, 0);
	if (map_block == NULL)
		return (NULL);
	return (map_block);
}

int	detach_block(t_int *map_block)
{
	if (shmdt(map_block) == IPC_RESULT_ERROR)
		return (1);
	return (0);
}