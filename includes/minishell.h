/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:13:37 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 12:37:02 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# define CWD_BUFFER_SIZE 1024

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
	char	*path;
	t_list	*redirs;
	//int				fd_in;
	//int				fd_out;
	//int				pipe_output;
	//char			*heredoc_delimiter;
	//t_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_shell //neded for expansions
{
	t_list	*env;
	char	**envp;
	int		last_status;
}	t_shell;

void	free_token(void *content);
void	free_cmd(void *content);
t_list	*ft_get_cmd_list(char *line, t_shell *sh);
t_list	*parser(t_list *tokens);
t_list	*lexer(char *line);
t_token	*new_token(enum e_token_type type, char *value, enum e_quote quote);
t_cmd	*new_cmd();
bool	is_redirection(t_token *token);
void	add_redirection(t_cmd *cmd, enum e_token_type type, char *file);
void	expander(t_list *cmds,  t_shell *shell);
t_shell	*init_shell(char **envp);
void	syntax_error(void);

//--DEBUG-HELPER-FUNC
int		ft_execute(t_list *cmds, t_shell *shell);
char	*get_path(t_cmd *cmd, t_shell *shell);
char	*find_path(t_shell *shell);
char	*get_key(char *envp);
char	*get_value(char *envp);
int		builtin_cd(char **argv);
int		builtin_env(t_shell *shell);
int		builtin_echo(char **argv);
int		builtin_pwd(void);
int		is_builtin(char *cmd);
int		execute_builtin(t_cmd *cmd, t_shell *shell);

void	print_token_node(void *node);
void	print_cmd_list(t_list *cmds);
void	println(char *s);
void	print_tokens_list(t_list *tokens);
void	print_cmd_list(t_list *cmds);
#endif