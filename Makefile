SRC = push_swap
CC = cc
CFLAGS = 

INC = -Iincludes
SRC_DIR = src/
SRC_FILES = main.c lst_utils.c ft_funcs.c
CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(CFILES:%.c=%.o)

all: $(SRC)

# Linker
$(SRC): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(SRC)

# compiling
%.o : %.c 
	$(CC)  -c $(INC) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -rf $(SRC)

re: fclean all
