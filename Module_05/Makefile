NAME = TrainSimulation

SRCS = Sources/main.cpp\
		Sources/Node.cpp\
		Sources/Rail.cpp\
		Sources/clear.cpp\
		Sources/Event.cpp\
		Sources/Train.cpp\
		Sources/Clock.cpp\
		Sources/parser.cpp\
		Sources/dijkstra.cpp\
		Sources/Simulation.cpp\

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -g
RM = rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

%.o: 			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@
				
clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
