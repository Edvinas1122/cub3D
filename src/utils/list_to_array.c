#include "utils.h"

void	print_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		printf("%s\n", str[i++]);
}

int	find_longest_line(t_list *lst)
{
	t_list	*node;
	int		max;
	int		current;

	node = lst;
	max = 0;
	current = ft_strlen(node->content);
	while (node)
	{
		max = ft_strlen(node->content);
		if (max < current)
			max = current;
		node = node->next;
	}
	return (max);
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
	int		longestline;

	node = lst;
	i2 = 0;
	while (i--)
		node = node->next;
	longestline = find_longest_line(lst);
	arr = ft_calloc(ft_lstsize(node) + 1, sizeof(char *));
	while (node)
	{
		str = ft_calloc(longestline + 1, sizeof(char));
		str = ft_memcpy(str, node->content, ft_strlen(node->content));
		arr[i2] = str;
		i2++;
		node = node->next;
	}
	print_arr(arr);
	return (arr);
}
