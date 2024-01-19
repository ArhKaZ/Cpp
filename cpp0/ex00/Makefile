#===========================VARIABLE===============================#
SRCS			:=	megaphone.cpp\

OBJS_D			:=	objs/

OBJS			:=	$(SRCS:%.cpp=$(OBJS_D)%.o)

NAME			:=	megaphone

#=========================FLAG===============================#
CC				:=	c++ -std=c++98

RM				:=	rm -rf

CFLAGS			:=	-Wall -Wextra -Werror

ASAN_F			:=	-g3 -fsanitize=address

#========================EXEC===============================#
all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS)
				$(CC) $(CFLAGS) $(ASAN_F) -o $(NAME) $(OBJS)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.cpp
				$(CC) $(CFLAGS) $(ASAN_F) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

FORCE			:

clean			:
				$(RM) $(OBJS) $(OBJS_D)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re FORCE
