/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:13:37 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/29 09:04:04 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# ifndef DEBUG_VERBOSE
#  define DEBUG_VERBOSE 0
# endif

enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_APPEND,
	T_HEREDOC,
	// T_AND,
	// T_OR,
	// T_LPAREN,
	// T_RPAREN,
	T_EOF
};

// enum Expression
// {
// 	Atom,
// 	Operation
// };

enum e_quote
{
	Q_NONE,
	Q_SINGLE,
	Q_DOUBLE
};

typedef struct s_token
{
	enum e_token_type	type;
	char				*value;
	enum e_quote		quote;
}	t_token;

typedef struct s_redir
{
	enum e_token_type	type;
	char				*file;
	//struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	int		argc;
	char	**argv;
	t_list	*redirs;
	//int				fd_in;
	//int				fd_out;
	//int				pipe_output;
	//char			*heredoc_delimiter;
	//t_cmd	*next;
}	t_cmd;

typedef struct s_env //save env this way to search usign key
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_shell //neded for expansions
{
	t_list	*env;
	int		last_status;
}	t_shell;

void	free_token(void *content);
void	free_cmd(void *content);
t_list	*ft_get_cmd_list(char *line, t_shell *sh);
t_list	*parser(t_list *tokens);
t_list	*lexer(char *line);
t_token	*new_token(enum e_token_type type, char *value, enum e_quote quote);
t_cmd	*new_cmd(void);
bool	is_redirection(t_token *token);
void	add_redirection(t_cmd *cmd, enum e_token_type type, char *file);
void	expander(t_list *cmds,  t_shell *shell);
t_shell	*init_shell(char **envp);
void	syntax_error(void);

char	*ft_strndup(const char *s, size_t n);

//--DEBUG-HELPER-FUNC
int		ft_execute(t_list *cmds, t_shell *shell);

void	print_token_node(void *node);
void	print_cmd_list(t_list *cmds);
void	println(char *s);
void	print_tokens_list(t_list *tokens);
void	print_cmd_list(t_list *cmds);
void	print_env_list(t_list *env_lst);
void	print_expanded_cmd_list(t_list *cmds);
#endif