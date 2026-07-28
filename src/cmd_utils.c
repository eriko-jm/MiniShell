/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 08:25:19 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 16:56:37 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		exit(1);//FIXME - malloc error: call error handler and clean befor exit
	cmd->argv = NULL;
	cmd->redirs = NULL;
	return (cmd);
}

void	add_redirection(t_cmd *cmd, enum e_token_type type, char *file)
{
	t_redir	*redir;
	//Allocate a t_redir.
	redir = malloc(sizeof(redir));
	if (!redir)
		exit(1);//FIXME - malloc error: call error handler and clean befor exit
	//Copy the type.
	redir->type = type;
	//Duplicate the filename.
	redir->file = ft_strdup(file);
	if (file && !redir->file)
		exit(1);//FIXME - malloc error: call error handler and clean befor exit
	//Wrap it in a t_list node.
	//Append it to cmd->redirs.
	ft_lstadd_back(&cmd->redirs, ft_lstnew(redir));
}
