/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:48:56 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/26 18:33:36 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;
	size_t	size;

	i = 0;
	a = (char *)dest;
	b = (char *)src;
	if (!a && !b)
		return (NULL);
	if (!n)
		return (dest);
	size = n;
	if (a > b)
	{
		while (i < n)
		{
			a[n - 1] = b[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(a, b, n);
	return (dest);
}
