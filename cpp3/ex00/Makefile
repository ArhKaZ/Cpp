#===========================VARIABLE===============================#
<<<<<<< HEAD
SRCS			:=	ClapTrap.cpp\
					main.cpp\
=======
SRCS			:=	ClapTrap.cpp \
					main.cpp \
>>>>>>> f6e1635053ffff3bc6d23596b262bdabbb818922

OBJS_D			:=	objs/

OBJS			:=	$(SRCS:%.cpp=$(OBJS_D)%.o)

HEAD_D			:=	incs/

<<<<<<< HEAD
HEAD			:=	ClapTrap.hpp\

HEAD_A			:=	$(addprefix $(HEAD_D), $(HEAD))

NAME			:=	claptrap
=======
HEAD			:=	ClapTrap.hpp \

HEAD_A			:=	$(addprefix $(HEAD_D), $(HEAD))

NAME			:=	ClapTrap
>>>>>>> f6e1635053ffff3bc6d23596b262bdabbb818922

#=========================FLAG===============================#
CC				:=	g++ -std=c++98

RM				:=	rm -rf

CFLAGS			:=	-Wall -Wextra -Werror

ASAN_F			:=	-g3 -fsanitize=address

#========================EXEC===============================#
all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS)
				$(CC) $(CFLAGS) $(ASAN_F) -o $(NAME) $(OBJS)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.cpp $(HEAD_A)
				$(CC) $(CFLAGS) $(ASAN_F) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

FORCE			:

clean			:
				$(RM) $(OBJS) $(OBJS_D)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean all

<<<<<<< HEAD
.PHONY			:	all clean fclean re FORCE
=======
.PHONY			:	all clean fclean re FORCE
>>>>>>> f6e1635053ffff3bc6d23596b262bdabbb818922
