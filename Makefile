# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 21:00:27 by gialexan          #+#    #+#              #
#    Updated: 2023/01/15 08:32:33 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ENCODER = 			encoder

DECODER =			decoder

ENCODER_FILE = 		main.c			\
					tree.c			\
					encode.c		\
					prints.c		\
					memory.c		\
					compress.c      \
					dictionary.c	\
					frequency.c		\
					linkedlist.c	\
					insertion_sort.c
					

DECODER_FILE =		main.c			\
					tree.c			\
					memory.c		\
					frequency.c		\
					linkedlist.c	\
					decompress.c	\
					insertion_sort.c

ENCODER_DIR = 		src_encoder

DECODER_DIR =		src_decoder

SRC_ENCODER = 		$(addprefix $(ENCODER_DIR)/,$(ENCODER_FILE))

SRC_DECODER =		$(addprefix $(DECODER_DIR)/, $(DECODER_FILE))

ENCODER_OBJ = 		$(SRC_ENCODER:.c=.o)

DECODER_OBJ =		$(SRC_DECODER:.c=.o)

RM = 				rm -f

CC = 				gcc

all:				$(ENCODER)

deco:				$(DECODER)

$(ENCODER):			$(ENCODER_OBJ)
					$(CC) $(ENCODER_OBJ) -lpthread -lrt -o $(ENCODER)

$(DECODER):			$(DECODER_OBJ)
					$(CC) $(DECODER_OBJ) -lpthread -lrt -o $(DECODER)

clean:
					$(RM) $(ENCODER_OBJ)
					$(RM) $(DECODER_OBJ)
					
fclean:				clean
					$(RM) $(ENCODER)
					$(RM) $(DECODER)

re:					fclean all

.PHONY:				all clean fclean re libft