#include "libft.h"

char	**add_last_arr(char **arr, char *str)
{
	int		i;
	char	**new;

	i = 0;
	while (arr[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while(arr[i])
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free_arr(arr);
	return(new);
}
