#include "utils.h"

void	print_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		printf("%s\n", str[i++]);
}

/*
	Returns a pointer to an allocated array 
	of the list contents copy

	Copies contents starting from list element at value
	of i
*/
char	**list_to_array_offset(t_list *lst, int i)
{
	t_list	*node;
	char	**arr;
	char	*str;
	int		i2;

	node = lst;
	i2 = 0;
	while (i--)
		node = node->next;
	arr = ft_calloc(ft_lstsize(node) + 1, sizeof(char *));
	while (node)
	{
		str = ft_calloc(ft_strlen(node->content), sizeof(char));
		str = ft_memcpy(str, node->content, ft_strlen(node->content));
		arr[i2] = str;
		i2++;
		node = node->next;
	}
	print_arr(arr);
	return(arr);
}
