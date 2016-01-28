#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 13

# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct		t_line
{
	int		fd;
	int		ret;
	char		*rest;
}			s_line;

int					get_next_line(int fd, char **line);

#endif


