/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:06:30 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/14 19:55:08 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list	*first_node;
// 	t_list	*second_node;
// 	t_list	*third_node;

// 	first_node = ft_lstnew("Primer nodo");
// 	second_node = ft_lstnew("Segundo nodo");
// 	third_node = ft_lstnew("Tercer nodo");

// 	first_node->next = second_node;
// 	// first_node->content = "Primer nodo";

// 	second_node->next = third_node;
// 	// second_node->content = "Segundo nodo";

// 	// third_node->content = "Tercer nodo";
// 	third_node->next = NULL;
// 	t_list	*last = ft_lstlast(first_node);
// 	printf("%s\n", (char *)last->content);
// 	free(first_node);
// 	free(second_node);
// 	free(third_node);
// 	return (1);
// }