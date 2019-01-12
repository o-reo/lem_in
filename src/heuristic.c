/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heuristic.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:49:28 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 11:57:36 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Returns the end room of the map
*/

t_room	*search_end(t_room *rooms)
{
	t_room	*current;

	current = rooms;
	while (current && current->cmd != ROOM_END)
		current = current->next;
	return (current);
}

/*
** Random int from 0 to n
*/

int		randint(int n)
{
	int		seed;

	return (ft_abs(((69069 * (int)&seed + 1) % 0x100000000) % n));
}

/*
** Selects a random element from table
*/

t_room	*random_room(t_room *room, size_t len, int min_cost)
{
	int		i;

	i = randint(len);
	while ((room + i)->cost < min_cost)
		i = randint(len);
	return (room + i);
}

/*
** Recursive function that calculates the cost
** Does not propagate if previous cost is inferior to the new
*/

void	iterate_cost(t_room *room, int cost)
{
	t_room	**link;
	size_t	len;
	int		tries;

	room->cost = room->cost > cost ? cost : room->cost;
	link = room->linked;
	len = ft_arraylen((void**)link);
	tries = 0;
	while (link && *link && tries < MAX_LINK)
	{
		if ((*link)->cost > cost + 1)
		{
			(*link)->cost = cost + 1;
			iterate_cost(*link, cost + 1);
			tries++;
		}
		link++;
	}
}

/*
** Calculates an heuristic cost relative to the distance from the end
*/

void	calculate_cost(t_room *rooms)
{
	t_room	*dest;

	dest = search_end(rooms);
	if (!dest)
	{
		error(!dest);
		return ;
	}
	iterate_cost(dest, 0);
}
