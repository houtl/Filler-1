/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:46:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/17 04:22:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

// DEBUG

# define CHECK(X) do{ft_putendl("_______");ft_putendl(#X);ft_putendl("_______");}while(0);

# include "libft.h"
# include <stdint.h>
# include "ft_printf.h"


# define CHAMP_NAME "sclolus.filler"
# define FILLER_NAME "sclolus.filler: "

# define PLAYER_SETTING_LINE "$$$ exec"
# define PLAYER_SETTING_LINE_LEN (sizeof(PLAYER_SETTING_LINE) - 1)

# define LAUNCHED "launched "

# define MAP_LENS_HEADER "Plateau "
# define MAP_LENS_HEADER_LEN (sizeof(MAP_LENS_HEADER) - 1)

# define PIECE_HEADER "Piece "
# define PIECE_HEADER_LEN (sizeof(PIECE_HEADER) - 1)

typedef int32_t	t_id;

typedef struct	s_coord
{
	uint32_t	x;
	uint32_t	y;
}				t_coord;

typedef struct	s_map
{
	uint64_t	*map;
	uint32_t	len_x;
	uint32_t	len_y;
	uint32_t	size;
	uint32_t	long_nbr;
}				t_map;

typedef struct	s_champ
{
	char		*player_name;
	t_map		map;
	t_coord		last_piece;
	uint32_t	liberties;
	t_id		player_number;
}				t_champ;

typedef struct	s_board
{
	uint32_t	len_x;
	uint32_t	len_y;
	uint32_t	size_longs;
	uint32_t	long_nbr;
	t_champ		player_1;
	t_champ		player_2;
}				t_board;

typedef struct	s_piece
{
	uint64_t	*lines;
	uint32_t	len_x;
	uint32_t	len_y;
	uint32_t	long_nbr;
	uint32_t	size_longs;
}				t_piece;

typedef struct	s_init_champs_f
{
	char		*id;
	int32_t		(*f)(char *, t_champ *);
}				t_init_champs_f;


/*
** Parsing
*/

int32_t			ft_get_board_stats(t_board *board);
uint32_t		*ft_get_filler_lens(char *line);
int32_t			ft_check_board_lines(t_list	*lst, t_board *board);
int32_t			ft_check_piece_lines(t_list	*lst, t_piece *piece);
uint32_t		ft_get_piece_stats(t_piece *piece);
void			ft_lst_push_back(t_list **lst, t_list *new);
uint32_t		ft_lines_to_long(t_list *lst, t_board *board);
uint32_t		ft_piece_to_long(t_list *lst, t_piece *piece);
t_piece			*ft_get_piece(void);

/*
** t_champ init()
*/

int32_t			ft_init_champs(t_list *lines, t_board *board);
int32_t			ft_init_champion(t_board *board);


/*
** Solve
*/

uint32_t		ft_solve(t_board *board, t_piece *piece);
uint32_t		ft_claim(t_piece *piece, t_board *board, t_coord pos);
uint32_t		ft_overwrite_board(t_piece *piece, t_board *board
					, t_coord pos);
uint32_t		ft_can_be_connected(t_piece *piece, t_board *board
									, t_coord pos);
t_map			*ft_get_sandbox_map(t_board *board);
uint32_t		ft_get_liberties(t_board *board
					, uint32_t player_index);
uint32_t		ft_get_liberties_after_claim(t_board *board, t_piece *piece
					, t_coord pos, uint32_t index_player);
uint32_t		ft_get_line_liberties(t_board *board, uint32_t player_index
									, uint32_t y);
void			ft_put_piece(t_map *map, t_piece *piece
							, t_coord pos);
t_coord			ft_get_pos(uint32_t index, t_board *board);
void			ft_print_coord(t_coord coord);
uint32_t		ft_get_manhattan_distance(t_board *board, uint32_t player_index
									  , t_coord pos);

/*
** Free functions
*/

void			ft_free_t_champ(t_champ *champ);
void			ft_free_champs(t_champ *champs);
void			ft_free_lst(t_list *lst);
void			ft_free_board(t_board *board);
void			ft_free_piece(t_piece *piece);

/*
** Error Handling
*/

# define INVALID_BOARD_LINE "Invalid Board line"
# define INVALID_MAP_HEADER "Parsing error in map header"
# define INVALID_LENS_FORMAT "Invalid lens format"

# define INVALID_PIECE_HEADER "Parsing error in piece header"
# define INVALID_PIECE_LINE "Invalid Piece line"

int32_t			ft_error(uint32_t n, char **str, int32_t return_status);
#endif

