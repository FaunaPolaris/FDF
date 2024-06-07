#include "libft.h"

char	*fp_strpadding(char *str, int padding)
{
	int		i;
	int		j;
	char	*output;
	int		len;

	if (!str)
		return (NULL);
	len = (int)fp_strlen(str);
	i = -1;
	j = -1;
	if (len > padding)
		return (NULL);
	output = (char *) fp_calloc(padding + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (++i < padding - len)
		output[i] = '0';
	while (++j < len)
		output[i++] = str[j];
	return (output);
}
