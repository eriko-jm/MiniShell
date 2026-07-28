/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:05:43 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 11:36:33 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//pratt is useful with presedences, with operators with different binding powers (&&, ||, (, ))
//overkill for mandatory part
// t_list	*pratt(t_list *tokens)
// {
// 	(void)tokens;
// 	t_list	*ats;

// 	ats = NULL;
// 	return (ats);
// }

//SECTION - helpers
t_token	*get_token(t_list *current)
{
	if (!current)
		return (NULL);
	return ((t_token *)current->content);
}

void	advance_list(t_list **current)
{
	if (*current)
		*current = (*current)->next;
}
//!SECTION

void	add_argument(t_cmd *cmd, char *value)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(value);
	if (!tmp)
		exit(1);//FIXME - malloc error: call error handler and clean befor exit
	i = 0;
	while (cmd->argv[i])
		i++;
	if (i < cmd->argc)
		cmd->argv[i] = tmp;
	else
		exit(2);//FIXME - catastrofic error: call error handler and clean befor exit
}

void	parse_redirection(t_cmd *cmd, t_list **current)
{
	enum e_token_type	type;
	t_token				*token;

	token = get_token(*current);
	type = token->type;
	advance_list(current);
	token = get_token(*current);
	if (token && token->type == T_WORD)
		add_redirection(cmd, type, token->value);
	else
		syntax_error();
	advance_list(current);
}

//count form current to pipe or eof
int	count_args(t_list *current)
{
	int	argc;

	argc = 0;
	while (current)
	{
		if (((t_token*)(current->content))->type == T_EOF)
			break ;
		else if (((t_token*)(current->content))->type == T_PIPE)
			break ;
		else if (((t_token*)(current->content))->type == T_WORD)
			argc++;
		if (is_redirection((t_token*)(current->content)))
			current = current->next;
		if (!current->next)
			break ;
		current = current->next;
	}
	return (argc);
}

t_cmd	*parse_command(t_list **tokens)
{
	t_cmd				*cmd;
	t_token				*token;

	cmd = new_cmd();
	//current = *tokens;
	//token = get_token(*tokens);
	cmd->argc = count_args(*tokens);//REVIEW - may be do it on new_cmd and de ft_calloc
	cmd->argv = NULL;
	if (cmd->argc > 0)
	{
		cmd->argv = ft_calloc(cmd->argc + 1, sizeof(char *));
		if (!cmd->argv)
			exit(1);//FIXME - malloc error: call error handler and clean befor ex
	}
	while (*tokens)
	{
		token = get_token(*tokens);
		if (token->type == T_EOF || token->type == T_PIPE)
			break ;
		if (token->type == T_WORD)
		{
			//parse_command(current);
			add_argument(cmd, token->value);
			advance_list(tokens);
		}
		else if (is_redirection(token))
			parse_redirection(cmd, tokens);
		else
			syntax_error();
		//*tokens = (*tokens)->next;
	}
	//push_cmd(cmd);
	//ft_lstadd_back(cmd_list, ft_lstnew(cmd));
	return (cmd);
}

t_list	*parse_commands(t_list **tokens)
{
	t_cmd	*cmd;
	t_list	*cmd_list;

	cmd_list = NULL;
	while (get_token(*tokens)->type != T_EOF)
	{
		cmd = parse_command(tokens);//the function moves the ponter
		ft_lstadd_back(&cmd_list, ft_lstnew(cmd));
		if (get_token(*tokens)->type == T_PIPE)
			advance_list(tokens);
	}
	return (cmd_list);
}

t_list	*parser(t_list *tokens)
{
	//ats = pratt(tokens);
	//ast = parse_commands(tokens);
	
	return (parse_commands(&tokens));
}
