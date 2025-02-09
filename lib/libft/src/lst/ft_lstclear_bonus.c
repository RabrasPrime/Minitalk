/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:12:38 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 11:14:25 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*tmp;

	if (!lst)
		return ;
	l = *lst;
	while (l)
	{
		tmp = l->next;
		ft_lstdelone(l, del);
		l = tmp;
	}
	*lst = NULL;
}
