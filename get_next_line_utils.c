/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:13:25 by dgutak            #+#    #+#             */
/*   Updated: 2023/07/16 21:24:01 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
	{
		*temp++ = '\0';
	}
}

/* char	*ft_strjoin(char*s1, char const *s2)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (len--)
	{
		if (*s1)
			ret[i++] = *s1++;
		else
			ret[i++] = *s2++;
	}
	if (s1 != 0)
		free(s1);
	ret[i] = '\0';
	return (ret);
} */
char	*ft_strjoin(char *resource, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!resource)
	{
		resource = malloc(1 * sizeof(char));
		resource[0] = '\0';
	}
	if (!buffer || !resource)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(resource) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (resource)
		while (resource[++i] != '\0')
			str[i] = resource[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(resource) + ft_strlen(buffer)] = '\0';
	free(resource);
	return (str);
}

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (n);
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}
