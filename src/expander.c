/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 02:44:24 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/29 15:24:47 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expand_word(char *word, t_shell *shell)
{
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

	if (!word || !*word)
		return (0);
	word;
	(void)shell;

	return (NULL);
}

void 	expand_argv(char **word, t_shell *shell)
{
	if (!word)
		return ;

	//recorrer array
	//por cada argumento
	//recorrer palabra buscando $  //obviamente solo cuando aplique, si esta dentro de comillas puede no aplicar la expansion
	//		si encuentra $ y debe expandir, verificar que no implique cambiar la cantidad de argumentos
	//				si hay que cambiar la catidad de argumentos, se necesita un nuevo array del nuevo len y copiar hasta donde el argumento revisado agregar los nuevos argumentos y copiar el resto
	expand_word(*word, shell);
}

void	expand_redirs(t_list *redir_lst, t_shell *shell)
{
	if (!redir_lst)
		return ;
	expand_word(((t_redir *)(redir_lst->content))->file, shell);
}

void	expander(t_list *cmds, t_shell *shell)
{
	while (cmds)
	{
		expand_argv(((t_cmd *)(cmds->content))->argv, shell);
		expand_redirs(((t_cmd *)(cmds->content))->redirs, shell);
		cmds = cmds->next;
	}
}
