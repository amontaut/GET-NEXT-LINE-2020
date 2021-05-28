/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:32:39 by amontaut          #+#    #+#             */
/*   Updated: 2020/12/19 13:23:18 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	int			i;

	i = 0;
	dest = dst;
	source = src;
	if (src == 0 && dst == 0)
		return (NULL);
	if (source < dest)
		while (len--)
			dest[len] = source[len];
	else
		while (len--)
			dest[i++] = *source++;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned long	i;

	if (s == NULL)
		return (NULL);
	if (!(res = (char *)malloc((sizeof(char)) * (len + 1))))
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		res[0] = '\0';
		return (res);
	}
	else
	{
		while (i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		l;
	int		i;

	l = 0;
	while (s1[l])
		l++;
	if (!(copy = (char *)malloc((l + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*res;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * \
					((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (++i < len2)
		res[i + len1] = s2[i];
	res[i + len1] = '\0';
	return (res);
}
