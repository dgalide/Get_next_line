#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
 #define BUFF_SIZE 10000

 #include <stdio.h>
 #include <fcntl.h>
 #include "libft/includes/libft.h"

typedef struct				s_rest
{
	char					*rest;
	int						fd;
}							t_rest;

int							get_next_line(int const fd, char **line);
int							ft_check_line(char *str);
char						*ft_get_line(char **str, int ret);

#endif
