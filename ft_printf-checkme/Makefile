

NAME = libftprintf.a

# Mandatory source files
SRCS = ft_printf.c ft_printf_utils.c

# Bonus source file (replaces ft_printf.o with bonus version)
BONUS_SRCS = ft_printf_bonus.c ft_printf_utils.c

# Object files
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

# Compiler flags
FLAGS = -Wall -Wextra -Werror

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Default target (mandatory)
all: $(NAME)

# Build mandatory version
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)✅ libftprintf.a (mandatory) created!$(RESET)"

# Build bonus version (replaces mandatory ft_printf with bonus version)
bonus: fclean
	@$(MAKE) SRCS="ft_printf_bonus.c ft_printf_utils.c" all
	@touch .bonus
	@echo "$(GREEN)✅ libftprintf.a (bonus) created!$(RESET)"

# Compile .c to .o
%.o: %.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(YELLOW)🔨 Compiled: $<$(RESET)"

# Clean object files
clean:
	@rm -f $(OBJS) ft_printf_bonus.o .bonus
	@echo "$(GREEN)🧹 Object files cleaned!$(RESET)"

# Full clean
fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🧹 Library removed!$(RESET)"

# Rebuild
re: fclean all

.PHONY: all bonus clean fclean re