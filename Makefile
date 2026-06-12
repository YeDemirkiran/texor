# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 15:15:20 by yademirk          #+#    #+#              #
#    Updated: 2026/06/12 15:21:36 by yademirk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := texor

CC := gcc
WFLAGS := -Wall -Wextra -Werror -pedantic
STD := -std=c99

SRC := $(addprefix src/, main.c)
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Creating executable '$@'...
	@$(CC) $(WFLAGS) $(STD) $^ -o $@

%.o: %.c
	@echo Compiling binary file '$@'...
	@$(CC) $(WFLAGS) $(STD) $< -c -o $@

clean:
	@echo Cleaning binary files...
	@rm -rf $(OBJ)

fclean: clean
	@echo Cleaning executable '$(NAME)'...
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
