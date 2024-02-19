/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:36:26 by nquecedo          #+#    #+#             */
/*   Updated: 2023/12/19 20:33:01 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstnew - Creates a new list node.
 * @content: The content to be placed in the new node.
 *
 * Return: A pointer to the new node, or NULL if the node could not be created.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(1 * sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node ->content = content;
	new_node ->next = NULL;
	return (new_node);
}

/*
============================================================
test
============================================================
*/
// #include <assert.h>
// void	test_check_content()
// {
// 	int	*value;
// 	t_list *node;
// 	value = malloc(sizeof(int));
// 	*value = 5;
// 	node = (ft_lstnew(value));
//	assert(*(int *)(node->content) == 5);
// 	printf("Test de contenido pasado \n");
// 	free(value);
// 	free(node);
// }
// void	test_chec_newxr_null()
// {
// 	int	*value;
// 	t_list *node;
// 	value = malloc(sizeof(int));
// 	*value = 5;
// 	node = (ft_lstnew(value));
// 	assert(node->next == NULL);
// 	printf("Test de netxt null pasado \n");
// 	free(value);
// 	free(node);
// }
// int main()
// {
// 	test_check_content();
// 	test_chec_newxr_null();
// 	return (0);
// }
