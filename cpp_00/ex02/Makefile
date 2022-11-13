# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 00:43:20 by fdaumas           #+#    #+#              #
#    Updated: 2022/10/18 19:39:51 by fdaumas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___SETUP
NAME			=	The_Job_Of_Your_Dreams
CC				=	c++
CSAN			=	-fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror -stdcm	++98 #$(CSAN)
RM				=	rm -rf

#	FILE & PATH
HEADER			=	Account.hpp

SRCS			=	test.cpp\
					Account.cpp

DIR_OBJS		=	.objs
LST_OBJS		=	$(SRCS:.cpp=.o)
OBJS			=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))


all:				${NAME}

${NAME}:			${OBJS}
			$(CC) $(CFLAGS) $^ -o $@

$(DIR_OBJS)/%.o:	%.cpp $(HEADER) Makefile $(HEADER) | $(DIR_OBJS)
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(DIR_OBJS):
			mkdir -p $(DIR_OBJS)

clean:
			$(RM) ${DIR_OBJS}

fclean:				clean
			$(RM) ${NAME}

re:					fclean all

.PHONY:		all clean fclean re bonus