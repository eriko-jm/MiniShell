/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:27:13 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 11:32:22 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//check syntax

//TODO - do something when a syntaxis error happen
//syntax error
void	syntax_error(void)
{
	exit(3);//FIX - call error function or error handler, something but exit
}
