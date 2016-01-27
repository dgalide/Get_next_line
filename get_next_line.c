#include "get_next_line.h"
#include <stdio.h>

void		check(int fd, t_list **lst)
{
	t_list  *tmp;
	s_line	*line;
	int	i;

	i = 1;
	tmp = *lst;
	if (tmp->content)
	{
		if (tmp->content->fd && tmp->content->fd == fd)
			return ;
		if (tmp->next)
			tmp = tmp->next;
		else
		{
			tmp->next = ft_lstnew(NULL, 0);
			tmp = tmp->next;
			line = (s_line *)malloc(sizeof(t_list));
			line->fd = fd;
			tmp->content = line;
		}
	}
	else
	{
		line = (s_line *)malloc(sizeof(s_line));
		line->fd = fd;
		line->rest = NULL;
		(*lst)->content = line;
	}
}

int			ft_read(s_line *line)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while ((ret = read(line->fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		line->ret = ret;
		tmp = line->rest;
		if (line->rest)
			line->rest = ft_strjoin(line->rest, buff);
		else
			line->rest = ft_strdup(buff);
		ft_memdel((void *)&tmp);
		if (ft_strchr(line->rest, '\n') != NULL)
			return (1);
	}
	return (0);
}

int			get_line(s_line *content, char **line)
{
	char		*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!content->rest)
		return (0);
	while (i < ft_strlen((char *)content->rest) && content->rest[i] != '\n')
		i++;
	if (i == ft_strlen((char *)(content->rest)))
	{
		*line = ft_strdup(content->rest);
		ft_memdel((void *)&content->rest);
		return (1);
	}
	else
	{
		tmp = content->rest;
		*line = ft_strsub(content->rest, 0, i);
		content->rest = ft_strchr(content->rest, '\n');
		content->rest++;
		ft_memdel((void *)&tmp);
		return (1);
	}
}

int			get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list		*tmp;
	int		i;

	i = 0;
	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		lst->content = NULL;
	}
	tmp = lst;
	check(fd, &lst);
	while (tmp->content->fd != fd)
		tmp = tmp->next;
	i = ft_read(tmp->content);
	if (i == -1)
	{
		ft_putchar('A');
		return (-1);
	}
	i = get_line(tmp->content, line);
	printf("line = %s\nrest = %s", *line, lst->content->rest);
	return (i);
}

int			main(int argc, char **argv)
{
	int fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	return (0);
}
