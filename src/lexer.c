/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:21:17 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 13:21:35 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int	ft_is_blank(int c)
{
	return (c == ' ' || c == '\t');
}

int	is_operator(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	skip_spaces(char **line)
{
	//DONE - spaces doesn't work exactly the same as ft_isspace. check and fix.
	//while (**line && ft_isspace(**line))
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
}

t_token	*read_word(char **line)
{
	char	*word;
	int		i;

	//buscar desde line ft_strncmp el siguiente operador o el EOF, todo lo que hay entre medio es WORD. Luego: analizar comillas y buen formateo de sintaxis
	i = 0;
	while ((*line)[i] && !is_operator((*line)[i]) && (!ft_is_blank((*line)[i]))) //TODO - encapsular ' ' y '\t' en is_cblank o algo asi y encapsular is operator is_quote y is_cblank juntas en isnt_word o algo asi
		i++;
	word = ft_substr(*line, 0, i);
	if (!word)
		exit(1);//FIXME - change for Error (MALLOC_ERROR)
	(*line) += i;
	return (new_token(T_WORD, word, Q_NONE));//FIXME - check quotation
}

t_token	*read_operator(char **line)
{
	t_token	*token;

	if (((*line)[0] == '<' && (*line)[1] == '<'))
		token = new_token(T_HEREDOC, "<<", Q_NONE);
	else if ((*line)[0] == '>' && (*line)[1] == '>')
		token = new_token(T_APPEND, ">>", Q_NONE);
	else if ((*line)[0] == '<')
		token = new_token(T_REDIR_IN, "<", Q_NONE);
	else if ((*line)[0] == '>')
		token = new_token(T_REDIR_OUT, ">", Q_NONE);
	else if ((*line)[0] == '|')
		token = new_token(T_PIPE, "|", Q_NONE);
	else
		exit(2);//FIXME - OPERATOR ERROR
	(*line)++;
	if (**line == '>' || **line == '<')
		(*line)++;
	return (token);
}

//void add_token(t_list **list, t_lexer *token);
//TODO - mandar is_blank, is_operator, is_quote y is_not_word a lexer_utils.c
// int	is_operator(int c)
// {
// 	if (c == '|' || c == '<' || c == '>')
// 		return (1);
// 	return (0);
// }

// What symbols are in this string? the list
t_list	*lexer(char *line)
{
	t_list	*tokens;
	//int		i;

	tokens = NULL;
	while (*line)
	{
		// i += skip_spaces(line + i);
		skip_spaces(&line);
		if (*line == '\0')
			break ;
		//if (is_operator(line + i))
		if (is_operator(*line))
			ft_lstadd_back(&tokens, ft_lstnew(read_operator(&line)));
		else
			ft_lstadd_back(&tokens, ft_lstnew(read_word(&line)));
	}
	//EOF token
	ft_lstadd_back(&tokens, ft_lstnew(new_token(T_EOF, "\0", Q_NONE)));
	return (tokens);
}
