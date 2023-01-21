# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:33:08 by cjudie            #+#    #+#              #
#    Updated: 2022/03/31 22:56:27 by cjudie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

CC  = gcc
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ./obj/
OBJDIRB = ./objb/
SRCDIR = ./
SRCDIR_B = ./bonus/
LIBFT = ./libft

HEAD = push_swap.h
HEAD_B = push_swap_bonus.h

SRC_LIST = reverse.c rotate.c swap.c\
				sorts.c utils_i.c utils_s.c\
				checker.c syntax.c utils_l.c push_swap.c\

SRCB_LIST =  bonus/check.c bonus/checker_b.c bonus/disposal.c \
  				bonus/disposal2.c bonus/main.c bonus/stack.c \
				bonus/get_next_line.c bonus/get_next_line_utils.c\


SRC = $(addprefix $(SRCDIR), $(SRC_LIST))
SRC_B = $(addprefix $(SRCDIR_B), $(SRCB_LIST))

OBJ  = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
OBJ_B = $(addprefix $(OBJDIRB), $(notdir $(SRC_B:.c=.o)))

LIBRARY = -L${LIBFT} -lft

.PHONY : all bonus clean fclean re

all: 		$(NAME)

$(NAME):	$(OBJ)
			make -C ${LIBFT}
			$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) -o $(NAME)

bonus: 		all $(NAME_B)

$(NAME_B): 	$(OBJ_B)
			$(CC) $(CFLAGS) $(OBJ_B) $(LIBRARY) -o $@

$(OBJDIR)%.o: %.c $(HEAD) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIRB)%.o: $(SRCDIR_B)%.c $(HEAD_B) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
		@mkdir $@ 

$(OBJDIRB):
		@mkdir $@ 

$(OBJ) : | $(OBJDIR)
$(OBJ_B) : | $(OBJDIRB)

clean:
	make -C ${LIBFT} clean
	rm -rf $(OBJDIR)
	rm -rf $(OBJDIRB)

fclean: clean
	make -C ${LIBFT} fclean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all