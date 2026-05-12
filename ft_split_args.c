/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:37:36 by abasilio          #+#    #+#             */
/*   Updated: 2026/05/12 21:07:22 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_args_len(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

static char	**ft_add_arg(char **args, char *arg)
{
	int		args_len;
	int		i;
	char	**new_args;

	if (!args)
		args_len = 0;
	else
		args_len = ft_args_len(args);
	new_args = malloc(sizeof(char *) * (args_len + 2));
	if (!new_args)
	{
		ft_free_multidim_arr(args);
		free(arg);
		return (NULL);
	}
	new_args[args_len + 1] = NULL;
	i = 0;
	while (args && args[i])
	{
		new_args[i] = args[i];
		i++;
	}
	new_args[i] = arg;
	free(args);
	return (new_args);
}

char	**ft_split_args(const char *s)
{
	char	**args;
	char	*new_arg;

	args = NULL;
	while (s && *s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			break ;
		new_arg = ft_extract_argument(&s);
		if (!new_arg)
		{
			ft_free_multidim_arr(args);
			return (NULL);
		}
		args = ft_add_arg(args, new_arg);
		if (!args)
			return (NULL);
		new_arg = NULL;
	}
	return (args);
}
