#include "../includes/so_long.h"

void	ft_trim_newline(char *str)
{
	int	len;

	if (!str)
		return;
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}
