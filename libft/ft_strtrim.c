/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:49:33 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*res;

	if (s == NULL)
		return (NULL);
	while (ft_strchr(" \t\n", (int)*s) && *s)
		s++;
	len = ft_strlen(s);
	while (ft_strchr(" \t\n", (int)*(s + len)) && *s)
		len--;
	res = ft_strsub(s, 0, len + 1);
	return (res);
}
