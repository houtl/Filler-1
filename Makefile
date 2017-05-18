NAME= sclolus.filler
SRC= srcs/main.c \
	srcs/ft_init_champion.c \
	srcs/ft_error.c \
	srcs/ft_free_champ.c \
	srcs/ft_free_lines.c \
	srcs/ft_free_champs.c \
	srcs/ft_free_board.c \
	srcs/ft_free_piece.c \
	srcs/ft_read_board.c \
	srcs/ft_lines_to_long.c \
	srcs/ft_piece_to_long.c \
	srcs/ft_check_board_lines.c \
	srcs/ft_lst_push_back.c \
	srcs/ft_get_piece.c \
	srcs/ft_check_piece_lines.c \
	srcs/ft_get_filler_lens.c \
	srcs/ft_read_piece.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -L./ft_printf -lftprintf -I./ft_printf/ -o $(NAME)

%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -I./ft_printf/ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
