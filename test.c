#include "ft_printf.h"
#include <fcntl.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	char **ptr;
	int i;

	i = 1;
	if (argc > 1)
	{
		ptr = ft_split(argv[2], 32);
		ft_printf("cmd: %s\n", ptr[0]);
		while (ptr[i])
		{
			ft_printf("args: %s\n", ptr[i]);
			i++;
		}
	}
	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
	return (0);
}
