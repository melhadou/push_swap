SRC = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
INC = -Iincludes

SRC_DIR = src/
SRC_FILES = main.c lst_utils.c ft_funcs.c utils.c sorting_algo.c chunks.c

UTILS_DIR = $(SRC_DIR)utils/
UTILS_FILES = helper_funcs.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ = $(CFILES:%.c=%.o)

all: $(SRC)

# Linking
$(SRC): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(SRC)

# compiling
%.o : %.c 
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -rf $(SRC)

re: fclean all
