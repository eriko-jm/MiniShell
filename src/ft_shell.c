/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 03:29:00 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 11:12:01 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	*init_shell(char **envp)
{
	t_shell	*sh;
	t_env	*node;

	sh = malloc(sizeof(t_shell));
	if (!sh)
		exit(1); //FIXME - malloc error: call error handler and clean befor exit
	sh->last_status = 0;
	sh->env = NULL;
	while (*envp)
	{
		//TODO - completar while
		node = malloc(sizeof(t_env));
		if (!node)
			exit(1);//FIXME - malloc error: call error handler and clean befor exit
		//read first part, save to 
		node->key = NULL;
		//everything else to
		node->value = NULL;
		//save node to list
		ft_lstadd_back(&sh->env, ft_lstnew(node));
		envp++;
	}
	return (sh);
}
