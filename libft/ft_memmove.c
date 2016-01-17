/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:41:29 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/14 15:44:39 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*str2;
	unsigned char	*str1;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (dst > src)
	{
		str1 = str1 + n;
		str2 = str2 + n;
		while (n != 0)
		{
			*--str1 = *--str2;
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
