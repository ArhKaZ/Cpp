#===========================VARIABLE===============================#
SRCS			:=	HumanA.cpp\
					HumanB.cpp\
					main.cpp\
					Weapon.cpp\

OBJS_D			:=	objs/

OBJS			:=	$(SRCS:%.cpp=$(OBJS_D)%.o)

HEAD_D			:=	incs/

HEAD			:=	HumanA.hpp\
					HumanB.hpp\
					Weapon.hpp\

HEAD_A			:=	$(addprefix $(HEAD_D), $(HEAD))

NAME			:= Versus

#=========================FLAG===============================#
CC				:=	c++ -std=c++98

RM				:=	rm -rf

CFLAGS			:=	-Wall -Wextra -Werror

ASAN_F			:=	-g3

#========================EXEC===============================#
all				:	$(NAME)

$(NAME)			:	$(OBJS_D) $(OBJS)
				$(CC) $(CFLAGS) $(ASAN_F) -o $(NAME) $(OBJS)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.cpp $(HEAD_A)
				$(CC) $(CFLAGS) $(ASAN_F) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

clean			:
				$(RM) $(OBJS) $(OBJS_D)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re FORCE