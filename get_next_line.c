/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:38:10 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/18 18:24:15 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				check_line(char *str, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '\n' || str[i] == EOF)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_read(int const fd, char **rest)
{
	int			ret;
	int			i;
	char		buff[BUFF_SIZE];
	char		*tmp;

	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == 0)
			return (0);
		if (ret == -1)
			return (-1);
		if (*rest)
		{
			tmp = *rest;
			*rest = ft_strjoin(*rest, ft_strsub(buff, 0, ret));
			free(tmp);
		}
		else
			*rest = ft_strsub(buff, 0, ret);
		if (check_line(*rest, ft_strlen((char *)*rest)) != -1)
			return (1);
	}
	return (0);
}

char			*get_line(char **str)
{
	char *cpy;
	char *tmp;
	int i;

	i = 0;
	if (*str)
	{
		if ((i = check_line(*str, ft_strlen((char *)*str)))	!= -1)
		{
			tmp = *str;
			cpy = ft_strsub(*str, 0, i);
			*str = ft_strsub(*str, (i + 1), ft_strlen((char *)*str) - (i + 1));
			free(tmp);
		}
		else
		{
			cpy = ft_strdup(*str);
			ft_memdel((void *)str);		
		}
		return (cpy);
	}
	else
		return (NULL);

}

int				get_next_line(int const fd, char **line)
{
	static char	*rest;
	int			i;

	i = ft_read(fd, &rest);
	if (i == -1)
		return (i);
	else if (i == 1)
	{
		*line = get_line(&rest);
		return (1);
	}
	else
	{
		*line = get_line(&rest);
		if (check_line(rest, ft_strlen((char *)rest)) )
		return (0);
	}

}

/*int		main(int argc, char **argv)
{
	int fd;
	int	i;
	int j;
	char *line;

	i = 1;
	j = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (i)
		{
			i = get_next_line(fd, &line);
			printf("i = %d |||| line = %s\n", i, line);
			j++;
		}
		return (i);
	}
	else
		return (0);
}*/
