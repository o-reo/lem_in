/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 17:04:25 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 18:59:51 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_rooms(t_room **rooms)
{
	t_room		*room;

	room = *rooms;
	while (room)
	{
		ft_printf("ROOM: name %s, cmd %s, x %i, y %i, ant %i\n",
		room->name, room->cmd, room->x, room->y, room->ant);
		room = room->next;
	}
}
