#include "ft_printf.h"
#include <fcntl.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	char **ptr;
	int i;

	i = 1;
	if(argc < 3)
		return (0);
	ptr = ft_split(argv[2], 32);
	ft_printf("cmd: %s\n", ptr[0]);
	while (ptr[i])
	{
		ft_printf("args: %s\n", ptr[i]);
		i++;
	}

	char *path;

	path = ft_strjoin("/usr/bin/", ptr[0]);
	ft_printf("\npath: %s\n", path);
	i = 0;
	//free split array and each word
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
	free(path);
	return (0);
}

