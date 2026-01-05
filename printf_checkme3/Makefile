# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 17:00:00 by yyuskiv           #+#    #+#              #
#    Updated: 2025/12/15 18:30:00 by yyuskiv          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

SRCS = ft_printf.c \
       ft_printf_utils.c \
       ft_printf_args.c \
       ft_printf_args2.c

SRCS_BONUS = ft_printf_bonus.c \
             ft_printf_utils.c \
             ft_printf_bonus_parse.c \
             ft_printf_bonus_utils.c \
             ft_printf_bonus_numbers.c \
             ft_printf_bonus_print.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(NC)"

bonus: .bonus

.bonus: $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS_BONUS)
	@touch .bonus
	@echo "$(GREEN)✓ $(NAME) created with bonus!$(NC)"

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(NC)"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS) .bonus
	@echo "$(RED)✗ Object files removed$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(NC)"

re: fclean all

test: $(NAME)
	@$(CC) $(CFLAGS) test.c -L. -lftprintf -o test
	@echo "$(GREEN)✓ Test compiled. Run: ./test$(NC)"

test_bonus: bonus
	@$(CC) $(CFLAGS) test_bonus.c -L. -lftprintf -o test_bonus
	@echo "$(GREEN)✓ Bonus test compiled. Run: ./test_bonus$(NC)"

norm:
	@norminette $(SRCS) $(SRCS_BONUS) ft_printf.h
	@echo "$(GREEN)✓ Norminette check completed$(NC)"

.PHONY: all bonus clean fclean re test test_bonus norm