/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 21:07:10 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 11:19:39 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_token(void *content)
{
	t_token	*tok;

	tok = (t_token *)content;
	free(tok->value);
	free(tok);
}

t_token	*new_token(enum e_token_type type, char *value, enum e_quote quote)
{
	t_token	*t;

	t = malloc(sizeof(t_token));

	if (!t)
		exit(1);//TODO - Call some 'error' function and clean all before exit
	t->type = type;
	t->value = ft_strdup(value);//REVIEW - Should instead get directly the pointer?
	if (t->value == NULL)
		exit(1);//FIXME - change for Error (MALLOC_ERROR)
	t->quote = quote; 

	return (t);
}
