SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

NAME = libft.a
CC = gcc
CFGLAGS = -Werror -Wextra -Wall

SRC_NAME  = ft_atoi.c \
                  ft_bzero.c \
                  ft_isalnum.c \
                  ft_isalpha.c \
                  ft_isascii.c \
                  ft_isdigit.c \
                  ft_isprint.c \
                  ft_memalloc.c \
                  ft_memccpy.c \
                  ft_memchr.c \
                  ft_memcmp.c \
                  ft_memcpy.c \
                  ft_memdel.c \
                  ft_memmove.c \
                  ft_memset.c \
                  ft_putchar.c \
                  ft_putchar_fd.c \
                  ft_putendl.c \
                  ft_putendl_fd.c \
                  ft_putnbr.c \
                  ft_putnbr_fd.c \
                  ft_putstr.c \
                  ft_putstr_fd.c \
                  ft_strcat.c \
                  ft_strchr.c \
                  ft_strclr.c \
                  ft_strcmp.c \
                  ft_strcpy.c \
                  ft_strdel.c \
                  ft_strdup.c \
                  ft_strequ.c \
                  ft_striter.c \
                  ft_striteri.c \
                  ft_strjoin.c \
                  ft_strlen.c \
                  ft_strmap.c \
                  ft_strmapi.c \
                  ft_strncat.c \
                  ft_strncmp.c \
                  ft_strncpy.c \
                  ft_strnequ.c \
                  ft_strnew.c \
                  ft_strnstr.c \
                  ft_strrchr.c \
                  ft_strstr.c \
                  ft_strsub.c \
                  ft_strtrim.c \
                  ft_tolower.c \
                  ft_toupper.c \
                  ft_itoa.c \
                  ft_strsplit.c \
                  ft_strlcat.c \
                  ft_lstnew.c \
                  ft_lstdelone.c \
                  ft_lstdel.c \
                  ft_lstadd.c \
                  ft_lstiter.c \
                  ft_lstmap.c \
                  ft_abs.c \
                  ft_ismaj.c \
                  ft_ismin.c \
                  ft_recursive_power.c \
                  ft_sqrt.c \
                  ft_strtolower.c \
                  ft_strtoupper.c \
                  ft_swap.c \
				  ft_free_splited_str.c \
                  get_next_line.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

norme:
	norminette $(SRC) $(INC_PATH)libft.h

clean:
	rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
