#include "utils.h"

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
	arr = malloc(sizeof(char *) * (ft_lstsize(node) + 1));
	while (node->next)
	{
		str = ft_calloc(ft_strlen(node->content), sizeof(char));
		str = ft_memcpy(str, node->content, ft_strlen(node->content));
		arr[i2] = str;
		node = node->next;
	}
	return(arr);
}
