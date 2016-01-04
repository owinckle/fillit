/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:22:04 by owinckle          #+#    #+#             */
/*   Updated: 2016/01/04 18:18:39 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fillit.h"

int	ft_error(void)
{
	ft_putstr("error\n\n\n");
	return(1);
}

int last(int col, int line, char *tet)
{
	int len;

	len = ft_strlen(tet) - 1;
	if (col == 1 && line == 1)
	{
		if (tet[len] == '\n')
			return (fouronly(tet));
	}
	return (ft_error());
}

int fouronly(char *tet)
{
	int i;
	int hashtag;
	int charcount;

	charcount = 1;
	hashtag = 0;
	i = -1;
	while (tet[i++])
	{
		if (tet[i] == '#')
			hashtag++;
		if (hashtag != 4 && charcount == 20)
			return (ft_error());
		if (charcount == 20)
		{
			charcount = 0;
			hashtag = 0;
		}
		charcount++;
	}
	return (shapes(tet, 0, 1, 1));
}

int poscheck(char *tet, int i, int col, int line)
{
	printf("Char envoye : %c\n", tet[i]);

	if (col > 1 && col < 4 && line > 1 && line < 4)
	{
		if (tet[i - 1] != '#' && tet[i + 1] != '#' && tet[i + 5] != '#'
				&& tet[i - 5] != '#')
			return (err(i, tet, col, line));
	}
	else if ((col == 1 && line == 1) || (col == 4 && line == 1) ||
			(col == 1 && line == 4) || (col == 4 && line == 4))
	{
		if (col == 1 && line == 1 && tet[1] != '#' && tet[5] != '#')
			return (err(i, tet, col, line));
		else if (col == 4 && line == 1 && tet[2] != '#' && tet[10] != '#')
			return (err(i, tet, col, line));
		else if (col == 1 && line == 4 && tet[10] != '#' && tet[16] != '#')
			return (err(i, tet, col, line));
		else if (col == 4 && line == 4 && tet[17] != '#' && tet[13])
			return (err(i, tet, col, line));
	}
	else
		sides(tet, i, col, line);
	return (0);
}

int sides(char *tet, int i, int col, int line)
{
	if (col > 1 && col < 4 && line == 1)
	{
		if (tet[i - 1] != '#' && tet[i + 1] != '#' && tet[i + 5] != '#')
			return (err(i, tet, col, line));
	}
	if (col > 1 && col < 4 && line == 4)
	{
		if (tet[i - 1] != '#' && tet[i + 1] != '#' && tet[i - 5] != '#')
			return (err(i, tet, col, line));
	}
	if (col == 1 && line > 1 && line < 4)
	{
		if (tet[i + 1] != '#' && tet[i + 5] != '#' && tet[i - 5] != '#')
			return (err(i, tet, col, line));
	}
	if (col == 4 && line > 1 && line < 4)
	{
		if (tet [i - 1] != '#' && tet[i + 5] != '#' && tet[i - 5])
			return (err(i, tet, col, line));
	}
	return (0);
}
