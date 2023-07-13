NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -g -fsanitize=address

LIBFT = libs/libft

INC = -Iincludes
LIBS = $(addprefix $(LIBFT), /libft.a)

SRC_DIR = src/
SRC_FILES = main.c lst_utils.c ft_funcs.c utils.c sorting_algo.c chunks.c


UTILS_DIR = $(SRC_DIR)utils/
UTILS_FILES = helper_funcs.c sort_three.c init_stack.c errors.c ft_free.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ = $(CFILES:%.c=%.o)

all: libft $(NAME)

libft:
	@echo "Making Libft"
	@cd $(LIBFT) && make

# Linking
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)

address: $(OBJ) libft
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -fsanitize=address -o $(NAME)

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
