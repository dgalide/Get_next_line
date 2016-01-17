/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:10:04 by dgalide           #+#    #+#             */
/*   Updated: 2015/11/30 20:45:29 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;

	i = (ft_strlen(s));
	d = (char)c;
	while (i >= 0)
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
