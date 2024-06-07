#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	char * str = fp_strpadding(argv[1], fp_atoi(argv[2]));
	if (!str)
		return (1);
	fp_printf("%s\n", str);
	free(str);
	return (0);
}
