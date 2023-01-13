# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 21:00:27 by gialexan          #+#    #+#              #
#    Updated: 2023/01/13 06:30:13 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ENCODER = 			encoder

#NAME_BONUS =		pipex_bonus

ENCODER_FILE = 		encoder.c 			\
					prints.c			\
					tree_utils.c 		\
					frequency_utils.c 	\
					linkedlist_utils.c	\
					dictionary_utils.c
					
					

#SRC_FILE_BONUS =	pipex_bonus.c cmd_bonus.c destroy_bonus.c exec_bonus.c

ENCODER_DIR = 		src_encoder

#SRC_DIR_BONUS =	src_bonus

SRC = 				$(addprefix $(ENCODER_DIR)/,$(ENCODER_FILE))

#SRC_BONUS =		$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILE_BONUS))

ENCODER_OBJ = 		$(SRC:.c=.o)

#SRC_OBJ_BONUS =	$(SRC_BONUS:.c=.o)

RM = 				rm -f

CC = 				gcc -g

all:				$(ENCODER)

bonus:				$(NAME_BONUS)

$(ENCODER):			$(ENCODER_OBJ)
					$(CC) $(ENCODER_OBJ) -o $(ENCODER)

#$(NAME_BONUS):		$(LIBFT) $(SRC_OBJ_BONUS)
#					$(CC) $(SRC_OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
					$(RM) $(ENCODER_OBJ)
#					$(RM) $(SRC_OBJ_BONUS)
					
fclean:				clean
					$(RM) $(ENCODER)
#					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft