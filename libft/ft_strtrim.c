#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_s1;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		len_s1 = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[len_s1 - 1] && ft_strchr(set, s1[len_s1 - 1]) && len_s1 > i)
			len_s1--;
		str = (char *)malloc(sizeof(char) * (len_s1 - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], len_s1 - i + 1);
	}
	return (str);
}
