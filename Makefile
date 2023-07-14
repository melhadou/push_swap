NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -fsanitize=leak -static-libasan -g
LIBFT = libs/libft

INC = -Iincludes
LIBS = $(addprefix $(LIBFT), /libft.a)

SRC_DIR = src/
SRC_FILES = main.c

SORTING_DIR= $(SRC_DIR)sorting/
SORTING_FILES = sort_five.c sort_four.c sort_others.c sort_three.c sorting_algo.c
SORTING_FILES += push_instructions.c rotate_instructions.c reverse_rotate_instructions.c swap_instructions.c

UTILS_DIR = $(SRC_DIR)utils/
UTILS_FILES = helper_funcs.c init_stack.c errors.c ft_free.c ft_tweaks.c lst_utils.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))
CFILES += $(addprefix $(SORTING_DIR), $(SORTING_FILES))

OBJ = $(CFILES:%.c=%.o)

all: libft $(NAME)

libft:
	@echo "Making Libft"
	@cd $(LIBFT) && make

# Linking
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)

# compiling
%.o : %.c 
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

clean:
	@cd $(LIBFT) && make clean
	rm -rf $(OBJ)

fclean: clean
	@cd $(LIBFT) && make fclean
	rm -rf $(SRC)

re: fclean all
