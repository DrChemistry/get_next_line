/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-rosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 08:10:44 by adi-rosa          #+#    #+#             */
/*   Updated: 2017/11/23 15:52:16 by adi-rosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*x;

	x = NULL;
	while (1)
	{
		if (*s == c)
			x = (char *)s;
		if (*s++ == '\0')
			return (x);
	}
}