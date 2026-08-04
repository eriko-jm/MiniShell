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

char	*get_key(char *envp)
{
	int		len;
	char	*key;

	len = ft_strchr(envp, '=') - envp;
	key = ft_substr(envp, 0, len);
	return (key);
}

char	*get_value(char *envp)
{
	char	*value;

	value = ft_strdup(ft_strchr(envp, '=') + 1);
	if (!value)
		return NULL;
	return (value);
}

char	**init_envp(char **envp)
{
	int	i;
	char	**en;

	i = 0;
	while (envp[i])
		i++;
	en = malloc(sizeof(char *) * (i + 1));
	if(!en)
		return (NULL);
	while (i >= 0)
	{
		if (envp[i])
			en[i] = ft_strdup(envp[i]);
		else
			en[i] = NULL;
		i--;
	}
	return(en);
}

t_shell	*init_shell(char **envp)
{
	t_shell	*sh;
	t_env	*node;
	t_list	*new;
	int		i;

	sh = malloc(sizeof(t_shell));
	if (!sh)
		exit(1);
	sh->last_status = 0;
	sh->envp = init_envp(envp);
	if(!sh->envp)
		exit(1);
	sh->env = NULL;
	i = 0;
	while (envp[i])
	{
		node = malloc(sizeof(t_env));
		if (!node)
			exit(1);
		node->key = get_key(envp[i]);
		node->value = get_value(envp[i]);
		if (!node->key || !node->value)
		{
			free(node->key);
    		free(node->value);
			free(node);
    		exit(1);
		}
		new = ft_lstnew(node);
		if (!new)
		{
			free(node->key);
			free(node->value);
			free(node);
			return (NULL);
		}
		ft_lstadd_back(&sh->env, new);
		i++;
	}
	return (sh);
}
