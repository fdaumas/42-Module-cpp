# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 00:43:20 by fdaumas           #+#    #+#              #
#    Updated: 2022/11/24 23:01:50 by fdaumas          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#___SETUP
NAME			=	bureaucrat
CC				=	c++
CSAN			=	-fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 #$(CSAN)
RM				=	rm -rf

#	FILE & PATH
HEADER			=	Bureaucrat.hpp\
					Form.hpp\
					RobotomyRequestForm.hpp\
					ShrubberyCreationForm.hpp\
					PresidentialPardonForm.hpp

SRCS			=	Bureaucrat.cpp\
					Form.cpp\
					PresidentialPardonForm.cpp\
					RobotomyRequestForm.cpp\
					ShrubberyCreationForm.cpp\
					main.cpp

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
			$(RM) ${NAME} *_shrubbery

re:					fclean
			make

.PHONY:		all clean fclean re bonus
