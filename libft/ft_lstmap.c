/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:38:30 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*start;

	tmp = f(lst);
	res = ft_lstnew(tmp->content, tmp->content_size);
	if (res == NULL)
		return (NULL);
	start = res;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		res->next = ft_lstnew(tmp->content, tmp->content_size);
		res = res->next;
		lst = lst->next;
	}
	return (start);
}
