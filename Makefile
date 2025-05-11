NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
PUSH_SWAP_FILES =push_functions.c\
				rotate_functions.c\
				reverse_rotate_functions.c\
				swap_functions.c \
				push_swap.c \
				assign_indexes.c \
				micro_sort.c \
				chiqui_sort.c \
				k_sort.c \
				validate.c \
				create_stack_and_parse.c\
				free.c\
				ft_split.c\
				lib_utils.c\
				main.c
FILES = $(PUSH_SWAP_FILES)
OBJS =$(FILES:.c=.o)



all: $(NAME)
$(NAME): $(OBJS)
	$(CC) -g $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)


re: fclean all
