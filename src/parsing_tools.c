/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_tools.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 12:59:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 18:21:06 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if a string is only digits
*/

int		ft_strisdigit(char *str)
{
	int		is_digit;

	is_digit = 1;
	while (*str && is_digit)
	{
		is_digit = ft_isdigit(*str) ? 1 : 0;
		str++;
	}
	return (is_digit);
}

/*
** Calculate the length of an array
*/

size_t	ft_arraylen(char **array)
{
	size_t	len;

	len = 0;
	while (*array)
	{
		array++;
		len++;
	}
	return (len);
}

/*
** Init a room, sets pointers to null and appends it to the list
*/

t_room	*create_room(t_room **rooms)
{
	t_room	*new_room;
	t_room	*tmp;

	if (!(new_room = malloc(sizeof(t_room))))
		return (NULL);
	new_room->name = NULL;
	new_room->linked = NULL;
	new_room->next = NULL;
	new_room->x = 0;
	new_room->y = 0;
	new_room->ant = 0;
	ft_bzero(new_room->cmd, 8);
	tmp = *rooms;
	if (tmp)
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
	}
	*rooms = *rooms ? *rooms : new_room;
	return (new_room);
}

/*
** Free the list of rooms at the end of the program
*/

void	free_rooms(t_room **rooms)
{
	t_room	*tmp;

	while(*rooms)
	{
		tmp = (*rooms)->next;
		free((*rooms)->name);
		free(*rooms);
		*rooms = tmp;
	}
}
