/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:51:31 by gialexan          #+#    #+#             */
/*   Updated: 2023/01/15 03:12:38 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#include <sys/sem.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>


#define BLOCK_SIZE 4096
#define	FILENAME "writeshmem.c"
#define IPC_RESULT_ERROR (-1)

key_t	key_block(char *filename);
int		detach_block(int *map_block);
int	*shared_block_map(int id_block);
int		shared_block_id(key_t key, int size);
#endif