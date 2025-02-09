/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:45 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 13:04:31 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lnew;
	t_list	*bcksave;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	lnew = NULL;
	bcksave = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		lnew = ft_lstnew(new_content);
		if (!lnew)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&bcksave, del);
			return (NULL);
		}
		ft_lstadd_back(&bcksave, lnew);
		lst = lst->next;
	}
	return (bcksave);
}
