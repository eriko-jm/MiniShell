// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   shell_parser_test.c                                :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abasilio <abasilio@student.42madrid.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/05/27 18:30:15 by abasilio          #+#    #+#             */
// /*   Updated: 2026/07/26 19:12:59 by abasilio         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../libft/libft.h"
// #define STDIN 0

// #include <stdio.h> //DELETE 

// //testing: cc shell_parser_test.c -I'../libft' '../libft/libft.a' -o test
// int main(int argc, char const *argv[], char *env[])
// {
// 	//read line by line from input (mostly terminal)
// 	//	- from a terminal in the case of an interactive shell
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(STDIN);
// 	while (line)
// 	{
// 		printf("%d. line read: %s", ++i, line);
// 		/*
// 		The shell:
// 			1. reads its input from a file, from the -c option or from the system() and popen() functions defined in the System Interfaces volume of IEEE Std 1003.1-2001. 
// 				* If the first line of a file of shell commands starts with the characters "#!", the results are unspecified.
// 				* The shell shall read its input in terms of lines from a file, from a terminal in the case of an interactive shell, or from a string in the case of sh -c or system().
// 				* Thel input lines can be of unlimited length. 
// 					- These lines shall be parsed using two major modes: 
// 						* ordinary token recognition and 
// 						* processing of here-documents.
// 			2. breaks the input into tokens: words and operators.
// 			3. parses the input into simple commands and compound commands.
// 			4. performs various expansions (separately) on different parts of each command, resulting in a list of pathnames and fields to be treated as a command and arguments.
// 			5. performs redirection and removes redirection operators and their operands from the parameter list.
			
// 			6. executes a function, built-in, executable file, or script, giving the names of the arguments as positional parameters numbered 1 to n, and the name of the command (or in the case of a function within a script, the name of the script) as the positional parameter numbered 0.
// 			7. optionally, waits for the command to complete and collects the exit status (see Exit Status for Commands).
// 		*/
// 		free(line);
// 		line = get_next_line(STDIN);
// 	}
// 	return (0);
// }
