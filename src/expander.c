/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 02:44:24 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 10:56:06 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expand_word(char *word, t_shell *shell)
{
	(void)word;
	(void)shell;

	return (NULL);
}

void 	expand_argv(char *word, t_shell *shell)
{
	expand_word(word, shell);
}

void	expand_redirs(char *word, t_shell *shell)
{
	expand_word(word, shell);
}

void	expander(t_list *cmds, t_shell *shell)
{
	//shell->env
	//Expand every argv[i]
	//Expand every redirection filename
	//for each command
	//{
	//	expand argv;
	//	expand redirections;
	//}

	while (cmds)
	{
		expand_argv(cmds->content, shell);
		expand_redirs(cmds->content, shell);
		cmds = cmds->next;
	}

	//ojo con el caso
	//VAR="a b c"
	//echo $VAR
	//se expande a:
	//echo a b c
	//entonces argv[1] = "$VAR"
	//deberia sustituir argv[1] por tres:
	//argv[1] = "a"
	//argv[2] = "b"
	//argv[3] = "c"

	//Handle $? -> the exit status that shell has already stored from the previously executed command
	//	- I'll need something like shell->last_status = 1;
	//Respect quote rules
}