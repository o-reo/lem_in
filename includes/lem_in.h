/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 12:38:20 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/02 15:10:35 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

/*
** VARIOUS CONSTANTS
*/

# define IS_ANT 0
# define ROOM_NODE 10
# define ROOM_START 11
# define ROOM_END 12
# define IS_LINK 2
# define IS_ENDED -1

/*
** ROOM STRUCTURE
*/

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				cmd;
	int				ant;
	struct s_room	**linked;
	struct s_room	*next;
}					t_room;

/*
** PARSING TOOLS
*/

t_room				*create_room(t_room **rooms);
void				free_rooms(t_room **rooms);
void				create_link(t_room **rooms, char **to_link);
t_room				**append_to_array(t_room **array, t_room *new_item);
int					macro_cmd(char *cmd);

/*
** VARIOUS UTILS
*/

int					ft_strisdigit(char *str);
size_t				ft_arraylen(char **array);
t_room				*search_room(t_room **rooms, char *name);
size_t				ft_roomlen(t_room **array);

/*
** DEBUG FUNCTIONS
*/

void				ft_print_rooms(t_room **rooms);

#endif
