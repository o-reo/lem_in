/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   moves.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:01:27 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:56:38 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Returns the room with the minimum cost
*/

t_room	*get_min_room(t_room **rooms)
{
	t_room	*best;

	best = NULL;
	while(rooms && *rooms)
	{
		if (!best || best->cost > (*rooms)->cost)
			best = *rooms;
		rooms++;
	}
	return (best);
}

/*
** Returns the starting room
*/

t_room	*search_start(t_room *rooms)
{
	t_room	*start;

	start = NULL;
	while(rooms && !start)
	{
		if (rooms->cmd == ROOM_START)
			start = rooms;
		rooms = rooms->next;
	}
	return (start);
}

/*
** Initialize turn by setting every ant to positive numbers
*/

void	init_turn(t_room *start_room)
{
	t_room	*room;

	room = start_room;
	while (room)
	{
		room->ant = ft_abs(room->ant);
		room = room->next;
	}
}

/*
** Gets the room containing an ant that has the lowest cost
*/

t_room	*next_room(t_room *rooms)
{
	t_room	*current;
	t_room	*next;
	int		is_movable;
	int		i;

	current = rooms;
	next = NULL;
	while (current)
	{
		if (current->ant > 0 && current->cmd != ROOM_END && (!next || current->cost < next->cost))
			next = current;
		current = current->next;
	}
	i = 0;
	is_movable = 0;
	while (current && current->linked && *(current->linked + i))
	{
		if ((*(current->linked + i))->ant >= 0)
			is_movable = 1;
		i++;
	}
	return (is_movable ? current : NULL);
}

/*
** Iterative ant moving, stops when every ant is at the end
** When a ant has been moved the number is set to negative
** Every ant is set to positive at the beginning the next turn
*/

void	move_ants(t_room *rooms)
{
	t_room		*min_room;
	t_room		*end_room;
	int			total_ants;
	t_room		*current;

	total_ants = search_start(rooms)->ant;
	end_room = search_end(rooms);
	current = rooms;
	while (end_room->ant < total_ants)
	{
		init_turn(rooms);
		current = next_room(rooms);
		while (current)
		{
			min_room = get_min_room(current->linked);
			ft_printf("L%i-%s ", ft_abs(current->ant), min_room->name);
			if (current->cmd == ROOM_START && min_room->ant == 0)
			{
				min_room->ant = -current->ant;
				current->ant--;
			} else if (min_room->cmd != ROOM_END && min_room->ant == 0)
			{
				min_room->ant = -current->ant;
				current->ant = 0;
			} else if (min_room == end_room)
			{
				end_room->ant++;
				current->ant = 0;
			}
			current = next_room(rooms);
		}
		write(1, "\n", 1);
	}
}
