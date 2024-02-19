/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:36:10 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/19 18:46:33 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstmap - Iterates the list 'lst' and applies the function 'f'
 *  to the content of each element.
 * @lst: The address of a pointer to the first link of a list.
 * @f: The address of the function used to iterate on the list.
 * @del: The address of the function used to delete the
 *  content of the element if needed.
 *
 * Return: The new list. NULL if the allocation fails.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*map_contnt;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		map_contnt = f(lst->content);
		new_node = ft_lstnew(map_contnt);
		if (!new_node)
		{
			if (map_contnt)
				del(map_contnt);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
