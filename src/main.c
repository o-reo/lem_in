/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 17:54:52 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 18:58:31 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parsing comments
*/

int		parse_comment(t_room **rooms, char *line)
{
	(void)rooms;
	(void)line;
	return (0);
}

/*
** Parsing room and adding it to the tree
** If it is a link return 2
** If it is the end return -1
** There is an invalid read in strsplit
*/

int		parse_room(t_room **rooms, char *line)
{
	char	**cols;
	t_room	*new_room;
	int		c;

	cols = ft_strsplit(line, ' ');
	if ((c = ft_arraylen(cols)) != 3){
		while (c)
			ft_strdel(cols + --c);
		ft_memdel((void**)&cols);
		return (2);
	}
	new_room = create_room(rooms);
	new_room->name = ft_strdup(cols[0]);
	new_room->x = ft_atoi(cols[1]);
	new_room->y = ft_atoi(cols[2]);
	while (c)
		ft_strdel(cols + --c);
	ft_memdel((void**)&cols);
	return (1);
}

/*
** Parsing link and adding it to the rooms
** If it is the end return -1
*/

int		parse_link(t_room **rooms, char *line)
{
	(void)rooms;
	(void)line;
	return (2);
}

/*
** Distributing input to appropriate Parser
*/

int		parser(t_room **rooms, char *line, int *section)
{
	int		ants;

	if (line[0] == '#')
	{
		return (1);
	}
	if (*section == 0)
	{
		ants = ft_atoi(line);
		*section = !ft_strisdigit(line) || ants == 0 ? -1 : 1;
	}
	else if (*section == 1)
	{
		*section = parse_room(rooms, line);
	}
	if (*section == 2)
	{
		*section = parse_link(rooms, line);
	}
	return (*section != -1);
}

/*
** Catch standard input and send it to parser
** !I will launch resolution after parsing just before return!
** There are still reachables on ft_readline because of the static
*/

int		main(void)
{
	char	*line;
	int		section;
	t_room	*rooms;
	int		c;

	rooms = NULL;
	section = 0;
	while ((c = ft_readline(0, &line)) == 1)
	{
		parser(&rooms, line, &section);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_print_rooms(&rooms);
	free_rooms(&rooms);
	return (0);
}
