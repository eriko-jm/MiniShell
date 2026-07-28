/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:19:57 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 12:37:11 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void free_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	// free argv
	// free redirs
	// close fds (?)
	free(cmd);
}

t_list	*ft_get_cmd_list(char *line, t_shell *sh)
{
	t_list	*tokens;
	t_list	*cmds;

	tokens = lexer(line);
	print_tokens_list(tokens);//FIX - Only for debug, delete!

	if (!tokens)
		return (NULL);

	cmds = parser(tokens);

	print_cmd_list(cmds);//FIX - Only for debug, delete!
	//free_token_list(tokens);
	ft_lstclear(&tokens, free_token);
	expander(cmds, sh);

	println("!!");//FIX - Delete!!
	return (cmds);
}

// t_cmd *ft_get_cmd_list(char *input_line)
// {
// 	t_list	*lexer_list;
// 	t_cmd	*cmd_list;

// 	lexer_list = lexstr(input_line);
// 	cmd_list = cmdlex(lexer_list);

// 	ft_lstclear(&lexer_list, free);

// 	return (cmd_list);
// }