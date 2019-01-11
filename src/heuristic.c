/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heuristic.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:49:28 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 18:12:07 by eruaud      ###    #+. /#+    ###.fr     */
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
** Selects a random element from table
*/

t_room	*random_room(t_room *room, size_t len, int min_cost)
{

}

/*
** Recursive function that calculates the cost
** Does not propagate if previous cost is inferior to the new
*/

void	iterate_cost(t_room *room, t_room *prev, int cost)
{
	t_room	**link;
	size_t	len;

	room->cost = room->cost > cost ? cost : room->cost;
	link = room->linked;
	len = ft_arraylen(link);
	while(link && *link){
		if (prev != *link && (*link)->cost > cost + 1){
			(*link)->cost =  cost + 1;
			iterate_cost(*link, room, cost + 1);
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
		return;
	}
	iterate_cost(dest, NULL, 0);
}
