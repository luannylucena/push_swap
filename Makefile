
NAME = push_swap

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libft/

SRCS = $(addprefix $(PATH_SRCS), push_swap.c \
		ft_fiding_index.c \
		choosing_sort.c \
		sort_three.c \
		writing_error.c \
		sort_up_to_five.c \
		free_stack.c \
		radix.c )\
		$(addprefix $(PATH_SRCS)movements/,\
		push.c\
		rotate.c\
		rrotate.c\
		swap.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

LIBFT = $(PATH_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -g
IFLAGS = -I $(PATH_INCL)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)movements/
	$(CC) $(CFLAGS) $(IFLAGS) -I ./libft/libft.h -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(PATH_LIBFT)

re: fclean all

PHONY: all clean fclean re