#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
 #define BUFF_SIZE 1

 #include <stdio.h>
 #include <fcntl.h>
 #include "libft.h"

int		get_next_line(int const fd, char **line);
int		ft_save(char *buff, char *save, char *rest);

#endif
