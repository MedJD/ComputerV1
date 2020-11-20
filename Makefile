# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 01:59:57 by mel-jadi          #+#    #+#              #
#    Updated: 2020/11/20 02:00:00 by mel-jadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= computerV1

SRCS = main.cpp \
	   solve.cpp \
	   reduced_form.cpp \
	   get_terms.cpp \
	   check_operators.cpp \
	   tools.cpp

SRC = $(SRCS:%=./%)
OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Wno-unused -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(CPPFLAGS) -o $(NAME) $^ 

%.o: ./%.cpp ./%.hpp
	@g++ $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
