/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_tools.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 12:59:38 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 13:09:19 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

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
	new_room->cmd = ROOM_NODE;
	tmp = *rooms;
	if (tmp)
	{
		while (tmp->next)
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

	while (*rooms)
	{
		tmp = (*rooms)->next;
		free((*rooms)->name);
		free((*rooms)->linked);
		free(*rooms);
		*rooms = tmp;
	}
}

/*
** Goes through the rooms and add links
*/

void	create_link(t_room **rooms, char **to_link)
{
	t_room		*link1;
	t_room		*link2;

	link1 = search_room(rooms, to_link[0]);
	link2 = search_room(rooms, to_link[1]);
	if (link1 && link2)
	{
		link1->linked = append_to_array(link1->linked, link2);
		link2->linked = append_to_array(link2->linked, link1);
	}
}

/*
** Reallocate linked array
** Does not append if the item is already present
** Will need to free all the memory!
*/

t_room	**append_to_array(t_room **array, t_room *new_item)
{
	int		n;
	t_room	**new_array;
	int		i;
	int		is_dup;

	n = ft_roomlen(array);
	if (!(new_array = ft_memalloc(sizeof(t_room*) * (n + 2))))
		return (NULL);
	i = 0;
	is_dup = 0;
	while (array && array[i])
	{
		new_array[i] = array[i];
		is_dup = array[i] == new_item ? 1 : 0;
		i++;
	}
	new_array[i] = is_dup ? NULL : new_item;
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}

/*
** Converts cmd to corresponding macro values
*/

int		macro_cmd(char *cmd)
{
	int		cmd_macro;

	cmd_macro = ROOM_NODE;
	cmd_macro = !ft_strcmp(cmd, "##start") ? ROOM_START : cmd_macro;
	cmd_macro = !ft_strcmp(cmd, "##end") ? ROOM_END : cmd_macro;
	return (cmd_macro);
}
