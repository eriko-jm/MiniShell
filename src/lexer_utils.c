/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 08:04:49 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/27 20:33:03 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//is_blank, is_operator, is_quote y is_not_word
//is_redirection

bool	is_redirection(t_token *token)
{
	if (token)
	{
		if (token->type == T_APPEND || token->type == T_HEREDOC\
			|| token->type == T_REDIR_IN || token->type == T_REDIR_OUT)
				return (true);
	}
	return (false);
}
