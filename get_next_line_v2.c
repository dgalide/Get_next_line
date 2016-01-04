#include "get_next_line.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	return (0);
}

int		ft_get_all(int const fd, char **rest)
{
	int	ret;
	char	buff[BUFF_SIZE];
	char	*tmp;

	while((ret = read(fd, buff, BUFF_SIZE)))	
	{
		ft_putchar('R');
		if (*rest)
		{
			ft_putchar('T');
			printf("%d\n", ret);
			tmp = *rest;
			*rest = ft_strjoin(*rest, ft_strsub(buff, 0, ret));
			free(tmp);
		}
		else
		{
			ft_putchar('S');
			*rest = ft_strsub(buff, 0, ret);
		}
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
	printf("%d\n", i);
	if (i == 0)
	{
		cpy = (char *)malloc(sizeof(char));
		cpy[0] = '\0';
	}
	else
	{
		ft_putchar('Z');
		cpy = ft_strsub(*str, 0, i);
		ft_putchar('Z');
	}
	if (!*str[i + 1])
	{
		ft_putchar('A');
		free(*str);
		*str = NULL;
		return (cpy);
	}
	else
	{
		ft_putchar('B');
		tmp = *str;
		*str = ft_strsub(*str, (i + 1), ft_strlen(*str) - (i + 2));
		free(tmp);
		return(cpy);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char	*rest;
	int	i;

	i = ft_get_all(fd, &rest);
	if (i == -1)
		return (-1);
	else
	{
		ft_putchar('X');
		*line = ft_get_line(&rest);
	}
	if (rest == NULL && i == 0)
		return (0);
	else
		return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int	i;
	char *line;

	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d\n", i);
	return (0);
}
