//
// Created by Leann Alaskan on 5/25/21.
//

#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H
# include  <unistd.h>
# include <stdio.h>
# include "get_next_line_utils.c"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE
	size_t BUFFER_SIZE = 50

int get_next_line(int fd, char **line);

#endif //GNL_GET_NEXT_LINE_H
