/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 12:38:20 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 18:06:36 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# define CINT_MAX 2147483647
# define CINT_MIN -2147483648

/*
** ROOM STRUCTURE
*/

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	char			cmd[8];
	int				ant;
	struct s_room	**linked;
	struct s_room	*next;
}					t_room;

/*
** PARSING TOOLS
*/

int					ft_strisdigit(char *str);
size_t				ft_arraylen(char **array);
t_room				*create_room(t_room **rooms);
void				free_rooms(t_room **rooms);

/*
** DEBUG FUNCTIONS
*/

void				ft_print_rooms(t_room **rooms);

#endif
