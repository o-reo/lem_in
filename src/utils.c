/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 18:17:18 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 13:56:13 by eruaud      ###    #+. /#+    ###.fr     */
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
** Calculate the length of t_room array
*/

size_t	ft_roomlen(t_room **array)
{
	size_t	len;

	if (!array)
		return (0);
	len = 0;
	while (*array)
	{
		array++;
		len++;
	}
	return (len);
}

/*
** Goes through rooms to search the matching name
*/

t_room	*search_room(t_room **rooms, char *name)
{
	t_room	*current;

	current = *rooms;
	while (current && strcmp(name, current->name) != 0)
		current = current->next;
	return (current);
}

/*
** Returns error
*/

int		error(int is_error)
{
	if (is_error){
		ft_printf("ERROR\n");
		return (-1);
	}
	else
		return (0);

}
