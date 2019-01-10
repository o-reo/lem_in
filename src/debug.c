/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 17:04:25 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 11:29:25 by eruaud      ###    #+. /#+    ###.fr     */
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
	while (room)
	{
		ft_printf("%s %i %i ",
		room->name, room->x, room->y);
		if (room->cmd != ROOM_NODE)
			ft_print_cmd(room->cmd);
		else
			ft_printf("\n");
		link = room->linked;
		/* while(*link)
		{
			ft_printf("%s-%s\n", room->name, (*link)->name);
			link++;
		}
		*/
		room = room->next;
	}
}
