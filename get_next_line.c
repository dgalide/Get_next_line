#include "get_next_line.h"
#include <stdio.h>

int			ft_check_line(char *line, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (line[i] == '\n' || line[i] == EOF)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_read(int fd, char **rest)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int		ret;

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = *rest;
		if (*rest)
			*rest = ft_strjoin(*rest, buff);
		else
			*rest = ft_strdup(buff);
		ft_memdel((void *)&tmp);
		if (ft_strchr(*rest, '\n') != NULL)
			return (1);
	}
	return (0);
}

int			get_line(char **rest, char **line)
{
	char		*tmp;
	int		i;

	i = 0;
	if (!*rest)
		return (0);
	i = ft_check_line(*rest, ft_strlen(*rest));
	if ((i + 1) == (int)ft_strlen((char *)(*rest)) || i == -1)
	{
		*line = ft_strdup(*rest);
		ft_memdel((void *)rest);
		return (1);
	}
	else
	{
		tmp = *rest;
		if (i == 0)
			*line = ft_strnew(1);
		else
			*line = ft_strsub(*rest, 0, i);
		*rest = ft_strdup(ft_strchr(*rest, '\n') + 1);
		ft_memdel((void *)&tmp);
		return (1);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*rest;
	int		i;

	i = ft_read(fd, &rest);
	if (i == -1)
		return (-1);
	i = get_line(&rest, line);
	return (i);
}
/*
int			main(int argc, char **argv)
{
	int fd;
	int fd1;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[2], O_RDONLY);
	printf("%d", get_next_line(fd, &line));
	ft_putendl(line);
	printf("%d", get_next_line(fd, &line));
	ft_putendl(line);
	printf("%d", get_next_line(fd, &line));
	return (0);
}*/
