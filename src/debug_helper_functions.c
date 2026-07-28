/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_helper_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:52:31 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 15:20:28 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

void	println(char *s)
{
	ft_printf("%s\n", s);
}

void	print_token_node(void *node)
{
	println("----------token---");
	ft_printf("Type: %d\n", ((t_token *)node)->type);
	ft_printf("Value: %s\n", ((t_token *)node)->value);
}
void	print_tokens_list(t_list *tokens)
{
	println("=========TOKENS Lst===========");
	ft_lstiter(tokens, print_token_node);
}

void	print_redir_node(void *node)
{
	t_redir	*redir;

	println("----------redir---");
	redir = (t_redir *)node;
	ft_printf("Type: %d\n", redir->type);
	ft_printf("File: %s\n", redir->file);
}

void	print_cmd_node(void *node)
{
	t_cmd	*cmd;
	int		i = 0;

	cmd = (t_cmd *)node;
	println("------cmd---------");
	ft_printf("Node argc: %d\n", cmd->argc);
	if (cmd->argc > 0)
	{
		ft_printf("Node argv: [");
		while (i < cmd->argc)
		{
			ft_printf("%s", cmd->argv[i]);
			if (cmd->argv[i + 1])
				ft_printf(", ");
			else
				ft_printf("]\n");
			i++;
		}
	}
	if (cmd->redirs)
		ft_lstiter(cmd->redirs, print_redir_node);
}

void	print_cmd_list(t_list *cmds)
{
	println("=========CMD Lst==============");
	ft_lstiter(cmds, print_cmd_node);
}
