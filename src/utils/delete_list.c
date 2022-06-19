#include "utils.h"

void	delete_list_node(void *lst)
{
	t_list	*node;

	node = lst;
	free(node->content);
	free(node);
}
