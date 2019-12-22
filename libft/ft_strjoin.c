/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:41:15 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL || (s1_len + s2_len + 1) == 0)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return (res);
	*(res + s1_len + s2_len + 1) = '\0';
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}
