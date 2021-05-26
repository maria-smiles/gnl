//
// Created by Leann Alaskan on 5/25/21.
//
#include "get_next_line.h"

char **ft_copy_n_char(char **line, char *buf, int i);
void ft_new_size(char *str1, char *str2);
int	read_from_fd(int fd, char *buf)
{
	int		rs;
	//size_t	BUFFER_SIZE = 1;
	rs = 0;
	rs = read(fd, buf, BUFFER_SIZE);
	//if read error
	//return (-1);
	buf[rs] = '\0';
	return (1);
}
int get_next_line(int fd, char **line)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	if (read_from_fd(fd, buf))
	{
		//find \n
		while (buf[i] != '\n' || buf[i] != '\0')
			i++;
		if (i < ft_strlen(buf))
			line = ft_copy_n_char(line, buf, i);
		else
			ft_new_size(str1, str2);

	}
	else
		return (-1);

}
char **ft_copy_n_char(char **line, char *buf, int i)
{
	static char *liner;
	char *bufr;

	bufr = ft_strdup(buf);
	bufr[i] = '\0';
	liner = malloc(sizeof(char) * (ft_strlen(*line) + i));
	liner = (ft_strjoin(*line, bufr);
	free(bufr);
	free(line)
	return (&liner);
}
void ft_new_size(char *str1, char *str2)
{

}