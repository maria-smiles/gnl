//
// Created by HardWorker on 01.06.2021.
//
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *check_ost(char *ost, char **line)
{
	char *p_n;

	p_n = NULL;
	if (ost)
	{
		if ((p_n = ft_strchr(ost, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++p_n);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost); //что она чистит?!
		}
	}
	else
	{
		*line = ft_clrnew(1);//ft_strnew аллоцирует переданное кол-во памяти и
		// заполняет нулями
	}
	return (p_n);
}

int get_next_line(int fd, char **line)///1, 0, -1
{
	char buf[BUFFER_SIZE + 1];
	int byte;
	char *p_n;
	static char *ost;
	char *tmp;

	p_n = check_ost(ost, line);
	while(!p_n && (byte = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte] = '\0';
		if((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			ost = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (byte == -1)
		return (-1);
	else if (byte != 0 || ft_strlen(ost) != 0 || ft_strlen(*line) != 0)
		return (1);
	else
		return (0);
}
