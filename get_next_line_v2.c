/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:42:15 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/17 19:57:54 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				*new_fd(t_list **lst, int fd)
{
	t_list			*tmp;
	t_rest			*new;

	tmp = *lst;
	new = (t_rest *)malloc(sizeof(t_rest));
	new->rest = NULL;
	new->fd = fd;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew((void *)new, sizeof(t_rest));
	}
	else
		*lst = ft_lstnew((void *)new, sizeof(t_rest));
}

int					get_next_line(int const fd, char **line)
{
	
}
