/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:01:30 by amontaut          #+#    #+#             */
/*   Updated: 2020/12/23 13:11:48 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	copy_first_line(char **xtra, char *buf)
{
	int	i;

	i = 0;
	if (!((*xtra) = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);
	while (i < BUFFER_SIZE)
	{
		(*xtra)[i] = buf[i];
		i++;
	}
	(*xtra)[i] = '\0';
	return (1);
}

int	copy_line(char **line, int i, char *xtra, int ret)
{
	int	len;

	*line = ft_substr(xtra, 0, i);
	i = i + ret;
	len = ft_strlen(xtra + i) + 1;
	ft_memmove(xtra, xtra + i, len);
	return (ret);
}

int	define_i(char **xtra)
{
	int i;

	i = 0;
	while ((*xtra)[i] && (*xtra)[i] != '\n' && (*xtra)[i] != '\0')
		i++;
	return (i);
}

int	empty_xtra(char **xtra, char *buf, char **line, int ret)
{
	int	i;

	i = 0;
	if ((*xtra) != NULL)
	{
		buf[ret] = '\0';
		*xtra = ft_strjoin(*xtra, buf);
		while ((*xtra)[i] && (*xtra)[i] != '\n' && (*xtra)[i] != '\0')
			i++;
		if ((*xtra)[i] == '\n')
			return (copy_line(line, i, *xtra, 1));
		else if ((copy_line(line, i, *xtra, 0)) || (*xtra)[i] == '\0')
		{
			free(*xtra);
			*xtra = NULL;
			return (0);
		}
	}
	else if (*(xtra) == NULL)
	{
		if (!(*line = malloc(sizeof(char *) * 1)))
			return (-1);
		(*line)[0] = '\0';
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*xtra;
	int			ret;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (xtra || (*line = NULL))
		i = define_i(&xtra);
	if (xtra && xtra[i] == '\n')
		return (copy_line(line, i, xtra, 1));
	while (((ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if (xtra == NULL && fd != STDIN_FILENO)
			copy_first_line(&xtra, buf);
		else
		{
			xtra = ft_strjoin(xtra, buf);
			i = define_i(&xtra);
			if (xtra && xtra[i] == '\n')
				return (copy_line(line, i, xtra, 1));
		}
	}
	return (empty_xtra(&xtra, buf, line, ret));
}
