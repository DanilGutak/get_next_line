/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:13:21 by dgutak            #+#    #+#             */
/*   Updated: 2023/07/17 14:12:14 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*take_line(char *buf)
{
	char	*ret;
	int		z;

	z = 0;
	if (!buf[z])
		return (NULL);
	while (buf[z] && buf[z] != '\n')
		z++;
	ret = ft_calloc(z + 2, sizeof(char));
	if (!ret)
		return (NULL);
	while (z >= 0)
	{
		ret[z] = buf[z];
		z--;
	}
	return (ret);
}

char	*delete_line(char *buf)
{
	int		z;
	int		s;
	char	*ret;

	z = 0;
	while (buf[z] && buf[z] != '\n')
		z++;
	if (!buf[z])
	{
		free(buf);
		return (NULL);
	}
	ret = ft_calloc(ft_strlen(buf) - z + 1, sizeof(char));
	if (!ret)
	{
		free(buf);
		return (NULL);
	}
	s = 0;
	z++;
	while (buf[z])
		ret[s++] = buf[z++];
	free(buf);
	return (ret);
}

char	*readf(int fd, char *buf)
{
	int		readen;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	readen = 1;
	while (!ft_strchr(buf, '\n') && readen != 0)
	{
		readen = read(fd, temp, BUFFER_SIZE);
		temp[readen] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	free(temp);
	return (buf);
}
/* char	*readf(int fd, char *resource)
{
	char	*buffer;
	int		reading_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reading_bytes = 1;
	while (!ft_strchr(resource, '\n') && reading_bytes != 0)
	{
		reading_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[reading_bytes] = '\0';
		resource = ft_strjoin(resource, buffer);
	}
	free(buffer);
	return (resource);
} */

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*ret;

	if (read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = 0;
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer[fd] = readf(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	ret = take_line(buffer[fd]);
	buffer[fd] = delete_line(buffer[fd]);
	return (ret);
}

/* #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	const char	*filename;
	int			fd;

	filename = "example.txt";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	char *kek =get_next_line(fd);
	char *kek1 =get_next_line(fd);
	char *kek2 =get_next_line(fd);
	char *kek3 =get_next_line(fd);
	printf("%s", kek);
	printf("%s", kek1);
	printf("%s", kek2);
	printf("%s", kek3);
	free(kek);
	free(kek1);
	free(kek2);
	free(kek3);
	printf("%d", BUFFER_SIZE);
	close(fd);
	return (0);
}
 */