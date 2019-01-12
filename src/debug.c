/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 17:04:25 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 13:27:06 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_cmd(int cmd)
{
	if (cmd == ROOM_START)
		ft_printf("START\n");
	else if (cmd == ROOM_END)
		ft_printf("END\n");
}

void	ft_print_rooms(t_room **rooms)
{
	t_room		*room;
	t_room		**link;

	room = *rooms;
	ft_printf("~~~~> ROOMS\n");
	while (room)
	{
		ft_printf("%s %i %i ",
		room->name, room->x, room->y);
		if (room->cost != INT_MAX)
			ft_printf("$%i ", room->cost);
		if (room->ant > 0)
			ft_printf("#%i ", room->ant);
		if (room->cmd != ROOM_NODE)
			ft_print_cmd(room->cmd);
		else
			ft_printf("\n");
		link = room->linked;
		while (link && *link)
		{
			ft_printf("%s-%s\n", room->name, (*link)->name);
			link++;
		}
		room = room->next;
	}
}

void	ft_has_cost(t_room **rooms)
{
	t_room	*room;

	room = *rooms;
	while (room)
	{
		if (room->cost == INT_MAX)
			ft_printf("ROOM %s has no cost\n", room->name);
		else
			ft_printf("ROOM %s has cost %i\n", room->name, room->cost);
		room = room->next;
	}
}
