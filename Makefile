# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalah <absalah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 00:37:05 by absalah           #+#    #+#              #
#    Updated: 2024/04/05 02:15:43 by absalah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME 	= checker

BONUS = ./bonus/checker_bonus.c \
		./bonus/get_next_line_bonus.c \
		./bonus/get_next_line_utils_bonus.c \
	  	./bonus/instructions/push_bonus.c \
	  	./bonus/instructions/rotate_bonus.c \
	  	./bonus/instructions/reverse_rotate_bonus.c \
	  	./bonus/instructions/swap_bonus.c \
	  	./bonus/utils/utils_for_sort_bonus.c \
	  	./bonus/parsing_indexing_bonus.c \
	  	./bonus/utils/my_libft_bonus.c \
	  	./bonus/utils/list_utils_bonus.c \
	  	./bonus/utils/my_libft_2_bonus.c \
	  	./bonus/utils/split_bonus.c \
	  

SRCS = 	./mandatory/push_swap.c \
	  	./mandatory/instructions/push.c \
	  	./mandatory/instructions/rotate.c \
	  	./mandatory/instructions/reverse_rotate.c \
	  	./mandatory/instructions/swap.c \
	  	./mandatory/utils/utils_for_sort.c \
	  	./mandatory/sort.c \
	  	./mandatory/parsing_indexing.c \
	  	./mandatory/utils/my_libft.c \
	  	./mandatory/utils/list_utils.c \
	  	./mandatory/utils/my_libft_2.c \
	  	./mandatory/utils/split.c 

OBJS		= $(SRCS:.c=.o)
BONUS_OBJ 	= $(BONUS:.c=.o)


CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)
bonus : $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ)

mandatory/%.o: mandatory/%.c mandatory/push_swap.h
	$(CC) -c $(CFLAGS) $< -o $@

bonus/%.o: bonus/%.c bonus/checker_bonus.h bonus/get_next_line_bonus.h
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	$(RM) $(OBJS) $(BONUS_OBJ)
fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	
re: fclean all

.PHONY: all clean fclean re
