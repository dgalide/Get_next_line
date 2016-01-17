/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:01:59 by dgalide           #+#    #+#             */
/*   Updated: 2015/11/30 20:42:01 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	size_t	i;

	d = (char)c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
