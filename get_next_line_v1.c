/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:38:10 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/17 16:40:07 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_check_line(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int				ft_read(int const fd, char **rest)
{
	int			ret;
	char		buff[BUFF_SIZE];
	char		*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-2);
		if (*rest)
		{
			tmp = *rest;
			*rest = ft_strjoin(*rest, ft_strsub(buff, 0, ret));
			free(tmp);
		}
		else
			*rest = ft_strsub(buff, 0, ret);
	}
	return (ret);
}

char			*ft_get_line(char **str, int ret)
{
	int			i;
	char		*tmp;
	char		*cpy;

	if (!*str)
		return (NULL);
	i = ft_check_line(*str);
	if (i == 0)
		cpy = ft_strnew(0);
	else if (i == -1 && ret == 0)
	{
		cpy = ft_strdup(*str);
		ft_memdel((void *)str);
	}
	else
		cpy = ft_strsub(*str, 0, i);
	if ((*str)[i + 1])
	{
		tmp = *str;
		*str = ft_strsub(*str, (i + 1), ft_strlen(*str) - (i + 1));
		free(tmp);
	}
	else
		ft_memdel((void **)str);
	return (cpy);
}

int				get_next_line(int const fd, char **line)
{
	static char	*rest;
	int			i;

	i = 0;
	if (rest)
	{
		if (ft_check_line(rest) == -1)
		{
			i = ft_read(fd, &rest);
			*line = ft_get_line(&rest, i);
		}
		else
			*line = ft_get_line(&rest, i);
	}
	else
	{
		i = ft_read(fd, &rest);
		*line = ft_get_line(&rest, i);
	}
	if (i == -1)
		return (-1);
	if (rest == NULL && i == 0)
		return (0);
	else
		return (1);
}

/*int		main(int argc, char **argv)
{
	int fd;
	int	i;
	char *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = get_next_line(fd, &line);
		return (i);
	}
	else
		return (0);
}*/
