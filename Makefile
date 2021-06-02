SRCS =	ft_strlen.c		ft_memset.c		ft_bzero.c		ft_calloc.c\
		ft_strlcpy.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c\
		ft_isprint.c	ft_isalnum.c	ft_itoa.c 		ft_memchr.c\
		ft_memcmp.c		ft_memcpy.c 	ft_memmove.c 	ft_putchar_fd.c\
		ft_memccpy.c	ft_putstr_fd.c 	ft_split.c		ft_putnbr_fd.c\
		ft_putendl_fd.c	ft_strchr.c		ft_strdup.c		ft_strjoin.c\
		ft_strlcat.c	ft_atoi.c		ft_strmapi.c 	ft_strncmp.c\
		ft_strnstr.c 	ft_strrchr.c 	ft_strtrim.c	ft_substr.c\
	   	ft_tolower.c 	ft_toupper.c	get_next_line.c	get_next_line_utils.c

FLAGS = -Wall -Wextra -Werror -g

HEAD = libft.h	get_next_line.h

NAME = libft.a

RM = rm -f

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	ar rcs $(NAME) $?

re: fclean all

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o} -MD

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *.out

.PHONY: all clean fclean re

so:
	cc -fPIC $(FLAGS) $(SRCS)
	gcc -shared -o libft.so $(OBJS)

ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
   endif
endif


#tests
TEST_STRCHR = test_strchr.c
test_strchr:
	clang $(FLAGS) ft_strlen.c $(TEST_STRCHR) -o test_strchr.out

TEST_STRJOIN = test_strjoin.c
test_strjoin:
	clang $(FLAGS) ft_strlen.c $(TEST_STRJOIN) -o test_strjoin.out

TEST_STRRCHR = test_strrchr.c
test_strrchr:
	clang $(FLAGS) ft_strlen.c $(TEST_STRRCHR) -o test_strrchr.out

TEST_ITOA = test_itoa.c
test_itoa:
	clang $(FLAGS) ft_strlcpy.c ft_strlen.c $(TEST_ITOA) -o test_itoa.out

TEST_SUBSTR = test_substr.c
test_substr:
	clang $(FLAGS) ft_strlen.c $(TEST_SUBSTR) -o test_substr.out

TEST_STRTRIM = test_strtrim.c
test_strtrim:
	clang $(FLAGS) ft_strlen.c $(TEST_STRTRIM) -o test_strtrim.out

TEST_SPLIT = test_split.c
test_split:
	clang $(FLAGS) ft_strlen.c ft_strlcpy.c $(TEST_SPLIT) -o test_split.out

TEST_STRNSTR = test_strnstr.c
test_strnstr:
	clang $(FLAGS) ft_strlen.c ft_memcmp.c ft_strncmp.c $(TEST_STRNSTR) -o test_strnstr.out

TEST_MEMCMP = test_memcmp.c
test_memcmp:
	clang $(FLAGS) ft_strlen.c $(TEST_MEMCMP) -o test_memcmp.out

TEST_MEMMOVE = test_memmove.c
test_memmove:
	clang $(FLAGS) ft_strlen.c $(TEST_MEMMOVE) -o test_memmove.out

TEST_STRNCMP = test_strncmp.c
test_strncmp:
	clang $(FLAGS) $(TEST_STRNCMP) -o test_strncmp.out

TEST_ATOI = test_atoi.c
test_atoi:
	clang $(FLAGS) $(TEST_ATOI) -o test_atoi.out

TEST_CALLOC = test_calloc.c
test_calloc:
	clang $(FLAGS) ft_bzero.c $(TEST_CALLOC) -o test_calloc.out

TEST_STRMAPI = test_strmapi.c
test_strmapi:
	clang $(FLAGS) ft_strlen.c ft_strncmp.c $(TEST_STRMAPI) -o test_strmapi.out

TEST_MEMCCPY = test_memccpy.c
test_memccpy:
	clang $(FLAGS) ft_memchr.c ft_memcpy.c  $(TEST_MEMCCPY) -o test_memccpy.out

TEST_STRLCAT = test_strlcat.c
test_strlcat:
	clang $(FLAGS) ft_strlen.c $(TEST_STRLCAT) -o test_strlcat.out

TEST_GNL = test_gnl.c
test_gnl:
	clang $(FLAGS) get_next_line.c get_next_line_utils.c $(TEST_GNL) -o test_gnl.out

test_build:
	gcc $(FLAGS) $(SRCS)



tests: re test_strrchr test_strchr test_itoa test_substr test_strtrim test_split test_strnstr test_memcmp test_strncmp test_strmapi test_memccpy

#end tests

