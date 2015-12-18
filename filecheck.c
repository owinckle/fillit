/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:11:49 by owinckle          #+#    #+#             */
/*   Updated: 2015/12/18 18:43:26 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 4096
#include "libft.h"
#include "fillit.h"

int g_len;

int		err(int i, char *tet, int col, int line)
{
	ft_putchar(tet[i]);
	ft_putstr("\nCeci est une erreur\n");
	ft_putnbr(i);
	ft_putstr("\ncol = ");
	ft_putnbr(col);
	ft_putstr("\nline = ");
	ft_putnbr(line);
	i -= 2;
	ft_putchar(tet[i]);
	return (1);
}

int		ft_error(void)
{
	ft_putstr("error");
	return (1);
}

int		lastchar(char *tet)
{
	int len;

	len = ft_strlen(tet);
	len = len - 2;
	if (tet[len] != '#' && tet[len] != '.')
		return (ft_error());
	len = len + 1;
	if (tet[len] != '\n')
		return (ft_error());
	return (norme(tet, 0, 1, 1));
}

void	getfile(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		len;

	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	lastchar(buf);
}

int		norme(char *tet, int i, int col, int line)
{
	g_len = ft_strlen(tet) - 1;
	while (i <= g_len)
	{
		if ((col <= 4 && line <= 4 && tet[i] != '.') && (col <= 4 && line
					<= 4 && tet[i] != '#'))
			return (ft_error());
		if (col == 5)
		{
			if (tet[i] != '\n')
				return (ft_error());
			col = 0;
			line++;
		}
		if (line == 5)
		{
			if (tet[i] != '\n')
				return (ft_error());
			line = 1;
			col = 0;
			i++;
		}
		i++;
		col++;
	}
	return (shapes(tet, 0, 1, 1);
}

int shapes(char *tet, int i, int col, int line)
{
	while(

