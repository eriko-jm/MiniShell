// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_extract_argument.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abasilio <abasilio@student.42madrid.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/04/06 20:22:05 by abasilio          #+#    #+#             */
// /*   Updated: 2026/05/30 15:15:25 by abasilio         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_minishell.h"

// static char	*ft_get_segment(const char *s, int len, char *current)
// {
// 	char	*new;
// 	char	*trailing;

// 	if (current)
// 	{
// 		trailing = ft_substr(s, 0, len);
// 		new = ft_strjoin(current, trailing);
// 		free(current);
// 		free(trailing);
// 	}
// 	else
// 		new = ft_substr(s, 0, len);
// 	return (new);
// }

// static char	*ft_final_arg(const char **s, int len, char *segment, int quote)
// {
// 	if (quote)
// 	{
// 		if (segment)
// 			free(segment);
// 		segment = NULL;
// 	}
// 	else
// 	{
// 		segment = ft_get_segment(*s, len, segment);
// 		*s += len;
// 	}
// 	return (segment);
// }

// static int	toggle_quote(int current, int quote_type)
// {
// 	if (current == quote_type)
// 		return (PLAIN);
// 	return (quote_type);
// }

// static void	ft_init_extract_argument(char **segment, int *len, enum \
// e_char_kind *quote)
// {
// 	*segment = NULL;
// 	*quote = PLAIN;
// 	*len = 0;
// }

// char	*ft_extract_argument(const char **s)
// {
// 	char				*segment;
// 	int					len;
// 	enum e_char_kind	quote;

// 	ft_init_extract_argument(&segment, &len, &quote);
// 	while (*s && (*s)[len] && (quote || !ft_isspace((*s)[len])))
// 	{
// 		if ((*s)[len] == SQ || (*s)[len] == DQ)
// 		{
// 			segment = ft_get_segment(*s, len, segment);
// 			if (!segment)
// 				return (NULL);
// 			if ((*s)[len] == SQ)
// 				quote = toggle_quote(quote, SINGLE_QUOTE);
// 			else
// 				quote = toggle_quote(quote, DOUBLE_QUOTE);
// 			*s = *s + len + 1;
// 			len = 0;
// 			continue ;
// 		}
// 		len++;
// 	}
// 	return (ft_final_arg(s, len, segment, quote));
// }
