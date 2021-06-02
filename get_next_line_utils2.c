//#include "get_next_line_utils.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char *ft_newstr(char	*new_s, char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	if (s2 == NULL)
		len_s2 = 0;
	else
		len_s2 = ft_strlen(s2);
	new_s = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new_s)
		return (NULL);
	while (i < len_s1)
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		new_s[i] = s2[i - len_s1];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;

	new_s = NULL;
	new_s = ft_newstr(new_s, s1, s2);
	return (new_s);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	i = 0;
	s2 = (char *) malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (&s2[0]);
}

void	*ft_memset (void *destination, int c, size_t n)
{
	char	*dest;

	dest = destination;
	while (n > 0)
	{
		*dest = (char) c;
		dest++;
		n--;
	}
	return (destination);
}