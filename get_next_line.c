#include "get_next_line.h"

int		ft_check_line(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_read(int const fd, char **rest)
{
	int	ret;
	int	i;
	char	buff[BUFF_SIZE];
	char	*tmp;

	while((ret = read(fd, buff, BUFF_SIZE)))	
	{
		if (*rest)
		{
			tmp = *rest;
			*rest = ft_strjoin(*rest, ft_strsub(buff, 0, ret));
			free(tmp);
		}
		else
			*rest = ft_strsub(buff, 0, ret);
		if (ret == -1)
			return (-2);
		if ((i = ft_check_line(*rest)) != -1)
			return (ret);
	}
	return (ret);
}

char		*ft_get_line(char **str)
{
	int	i;
	char	*tmp;
	char	*cpy;

	if (!*str)
		return (NULL);
	i = ft_check_line(*str);
	if (i == 0)
		ft_bzero((char *)cpy, 1);
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

int		get_next_line(int const fd, char **line)
{
	static char	*rest;
	int	i;
	int	j;

	if (rest)
	{
		if (ft_check_line(rest) == -1)
		{
			j = ft_read(fd, &rest);
			if (j == -2)
				return (-1);
			*line = ft_get_line(&rest);
		}
		else
			*line = ft_get_line(&rest);
	}
	else
	{
		i = ft_read(fd, &rest);
		*line = ft_get_line(&rest);
		if (i == -2)
			return (i);
	}
	if (rest == NULL)
		return (0);
	else
		return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int	i;
	int	j;
	char *line;

	fd = open(argv[1], O_RDONLY);
	i = 1;
	j = 0;
	//while (i != 0)
	//{
		i = get_next_line(fd, &line);
		printf("%s\n", line);
	//}
	return (0);
}
