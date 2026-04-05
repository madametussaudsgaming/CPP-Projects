# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/01 16:41:09 by rpadasia          #+#    #+#              #
#    Updated: 2026/04/05 18:13:06 by rpadasia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucratIII

SRC = srcs/Bureaucrat.cpp srcs/main.cpp srcs/AForm.cpp srcs/ShrubberyCreationForm.cpp
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR) $(OBJDIR)/srcs

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) *_shrubbery

re: fclean all

.PHONY: all clean fclean re