/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 17:54:52 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:47:58 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parsing comments
*/

void	parse_comment(char *line, int *section)
{
	size_t		len;

	len = ft_strlen(line);
	if (len > 2 && line[1] == '#')
		*section = macro_cmd(line);
}

/*
** Parsing room and adding it to the tree
** If it is a link return IS_LINK
** If it is the end return IS_ENDED
** There is an invalid read in strsplit
*/

int		parse_room(t_room **rooms, char *line, int cmd)
{
	char	**cols;
	t_room	*new_room;
	int		c;

	cols = ft_strsplit(line, ' ');
	if ((c = ft_arraylen(cols)) != 3)
	{
		while (c)
			ft_strdel(cols + --c);
		ft_memdel((void**)&cols);
		return (IS_LINK);
	}
	new_room = create_room(rooms);
	new_room->name = ft_strdup(cols[0]);
	new_room->x = ft_atoi(cols[1]);
	new_room->y = ft_atoi(cols[2]);
	new_room->cmd = cmd;
	while (c)
		ft_strdel(cols + --c);
	ft_memdel((void**)&cols);
	return (ROOM_NODE);
}

/*
** Parsing link and adding it to the rooms
** If it is the end return -1
*/

int		parse_link(t_room **rooms, char *line)
{
	char	**cols;
	int		c;

	cols = ft_strsplit(line, '-');
	if ((c = ft_arraylen(cols)) != 2)
	{
		while (c)
			ft_strdel(cols + --c);
		ft_memdel((void**)&cols);
		return (IS_ENDED);
	}
	create_link(rooms, cols);
	return (IS_LINK);
}

/*
** Distributing input to appropriate Parser
*/

int		parser(t_room **rooms, char *line, int *section)
{
	int		ants;

	if (line[0] == '#')
		parse_comment(line, section);
	else if (*section == IS_ANT)
	{
		ants = ft_atoi(line);
		*section = !ft_strisdigit(line) || ants == 0 ? IS_ENDED : ROOM_NODE;
	}
	else if (*section == ROOM_NODE || *section == ROOM_START || *section == ROOM_END)
	{
		*section = parse_room(rooms, line, *section);
	}
	if (line[0] != '#' && *section == IS_LINK)
		 *section = parse_link(rooms, line);
	return (*section != IS_ENDED);
}

/*
** Catch standard input and send it to parser
** !I will launch resolution after parsing just before return!
** There are still reachables on ft_readline because of the damn static
** Added a -q option to not print the input
*/

int		main(int ac, char **av)
{
	char	*line;
	int		section;
	t_room	*rooms;
	int		c;

	rooms = NULL;
	section = IS_ANT;
	while ((c = ft_readline(0, &line)) == 1)
	{
		ac != 1 && !ft_strcmp(av[1], "-q") ? 0 : ft_printf("%s\n", line);
		parser(&rooms, line, &section);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_print_rooms(&rooms);
	free_rooms(&rooms);
	return (0);
}
