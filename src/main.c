/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:51:04 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 18:12:26 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// /// @brief get a  list of tokens from the input given
// /// @param input_line 
// /// @param lst 
// /// @return 
// t_list	*lexstr(char *input_line)
// {
// 	t_lexer	*content;
	
// 	//TODO - while input_line not EOF
// 	//TODO - get the input fragment that represents the token
// 	// content = input_line; //FIXME - content should be every token identified
// 	content = malloc(sizeof(t_lexer));

// 	content->type = T_WORD;
// 	ft_strlcpy(content->value, input_line, ft_strlen(input_line));

// 	//split every word into tokens:
// 	//ft_split_args

// 	ft_lstadd_back(lst, ft_lstnew(content));
// 	//TODO - advance the reading head
// 	//TODO - end while
// 	//lex form imput line
// 	//return a lexer list of all elements on the input

// 	ft_lstiter(*lst, print_token_node); //FIXME - for debugging purposes only, delete!
// 	return (lst);
// }

// t_cmd	*cmdlex(t_list	*lexer_list)
// {
// 	(void)lexer_list;
// 	//given the lexer use Pratt Parsing to create the execution three
// 	return (NULL);
// }

// void	print_cmd_list(t_cmd *cmd_list)
// {
// 	(void)cmd_list;
// 	//print the content of cmd_list
// }

// int main(int argc, char const *argv[], char *envp[])
// {
// 	(void)envp; //FIXME - delete this line
// 	(void)argv; //FIXME - delete this line
// 	t_cmd	*cmd_list;
// 	char	*input_line;
// 	//t_shell *shell; // - should we have a t_shell to wrap all confings?
// 	//shell = malloc(sizeof(t_shell)); //FIXME - 
// 	// if (!shell)
// 	// 	exit(1);
// 	if (argc != 1)
// 	{
// 		write(2, "Wrong number of args.\n", 22);
// 		exit(1);
// 	}
// 	//while (shell.state = RUNNING)
// 	//input_line = readline(shell.cur_dir+"minishell$ "); //TODO - El nombre, deberia incluir el directorio o el usuario? en ENV deberia mantener cual es el directiorio actual o manejar como manbiarlo.
// 	input_line = readline("minishell$ ");
// 	while (input_line)
// 	{
// 		cmd_list = NULL;
// 		ft_printf("DEBUG - linea leida: %s\n", input_line);//TODO - delete line
// 		add_history(input_line);
// 		cmd_list = ft_get_cmd_list(input_line);
// 		print_cmd_list(cmd_list); //FIXME - reeplace with execution call
		
// 		ft_lstclear(&cmd_list, free); //esto puede encapsularse en free_lst y que reciba una lst generica y una funcion generica y llame el lst_clear y ponga todo a null.
// 		free(cmd_list);
// 		cmd_list = NULL;

// 		free(input_line);
// 		input_line = readline("minishell$ ");
// 	}
// 	ft_printf("exit\n");
// 	return (0);
// }

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	
	char	*line;
	t_list	*cmds;
	t_shell	*shell;

	if (argc != 1)
		return (1);

	shell = init_shell(envp);
	print_env_list(shell->env);//FIXME - Only for debug, delete!
	line = readline("minishell$ ");
	while (line)
	{
		if (*line)
			add_history(line);
		cmds = ft_get_cmd_list(line, shell);
		if (cmds)
		{
			shell->last_status = ft_execute(cmds, shell); //REVIEW - how to save the last status for expander use
			//free_cmd_list(cmds);
			ft_lstclear(&cmds, free_cmd);
		}
		free(line);
		line = readline("minishell$ ");
	}
	printf("exit\n");
	return (0);
}
