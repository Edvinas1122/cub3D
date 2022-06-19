#include "utils.h"

/* 
	Compares string to a character
	if does not match return 0
	if matches returns 1
*/
int	compare_to_str2(char c, char *valid_char)
{
	int	i;
	int	matching;

	i = 0;
	matching = 0;
	while (valid_char[i])
	{
		if (c == valid_char[i])
			matching = 1;
		i++;
	}
	return (matching);
}

// implament return instead of exit
/* 
	Compares string to a character
	if does not match then terminates program
*/
void	compare_to_str(char c, char *valid_char)
{
	int	i;
	int	matching;

	i = 0;
	matching = 0;
	while (valid_char[i])
	{
		if (c == valid_char[i])
			matching = 1;
		i++;
	}
	if (!matching)
		exit(0);
}
