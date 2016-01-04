/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:52:58 by owinckle          #+#    #+#             */
/*   Updated: 2016/01/04 17:58:41 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

void	getfile(int fd);
int		norme(char *tet, int i, int col, int line);
int		ft_error();
int		lastchar(char *tet);
int		shapes(char *tet, int i, int col, int line);
int		last(int col, int line, char *tet);
int		fouronly(char *tet);
int		poscheck(char *tet, int i, int col, int line);
int		sides(char *tet, int i, int col, int line);
int		err(int i, char *tet, int col, int line);
#endif
