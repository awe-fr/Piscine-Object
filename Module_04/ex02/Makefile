NAME = Factory

SRCS = main.cpp\

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
				
clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
