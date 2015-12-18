/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:08:13 by owinckle          #+#    #+#             */
/*   Updated: 2015/12/18 18:43:20 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		return (ft_error());
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error());
	getfile(fd);
	if (close(fd) == -1)
		return (ft_error());
	return (0);
}
