# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 00:00:00 by student           #+#    #+#              #
#    Updated: 2024/12/23 00:00:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a
BONUS_NAME	= get_next_line_bonus.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

# Mandatory files
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

# Bonus files
BONUS_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

# Colors for output
GREEN		= \033[0;32m
RESET		= \033[0m

# Default buffer size
ifndef BUFFER_SIZE
	BUFFER_SIZE = 42
endif

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) created$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(AR) $(BONUS_NAME) $(BONUS_OBJS)
	@echo "$(GREEN)✓ $(BONUS_NAME) created$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(RESET)"

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(GREEN)✓ All files cleaned$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re