# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2019/10/14 17:36:37 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
COMPILER=gcc
FLAGS=-g3 -Wall -Wextra -Werror -MMD -MP
CC=gcc $(FLAGS) -c -I$(PATH_1HDR) -I$(PATH_2HDR)

# --- 1.Source ---------------------------------------------------------------

_PUT=	putchar putchar_fd putendl putendl_fd putnbr putnbr_fd putstr putstr_fd
_MEM=	memdel bzero memset memcpy memccpy memmove memchr memalloc memcmp
_LIST=	lstnew lstdelone lstdel lstadd lstmap lstccpy lstiter lstinsert \
		lstappend lstfree lstsize
_IS=	isalpha isdigit isalnum isascii isprint iswhitespace
_TO=	atoi toupper tolower itoa atozu
STRCHR=	strchr strcmp strncmp strstr strnstr strequ strnequ strastr strastri \
		strchri strlen wstrlen wcharlen strcmp strlcmp strnchri strrstr strrchr
STRSET=	strcat strncat strlcat strclr strcpy strncpy strdel strdup strjoin \
		strnew strsub strtrim striter striteri strmap strmapi pathjoin \
		free_sarray
_PARSE=	strsplit strssplit gnl flagarg
_MATH=	abs
_LIBFT=	$(_PUT) $(_MEM) $(_LIST) $(_IS) $(_TO) $(STRCHR) $(STRSET) $(_PARSE) \
		$(_MATH)

PRINTF=	ft_printf pf_buffer pf_number pf_number_2 pf_other pf_parsing \
		pf_string pf_double pf_string_2
_FTOA=	f_bigint f_create_unit f_operand f_create_stack f_free_precision \
		f_putnbr
SRC=$(_LIBFT:%=ft_%) $(PRINTF) $(_FTOA)

# --- 2.Path -------------------------------------------------------------------

VPATH=srcs:srcs/printf:srcs/printf/ftoa
PATH_OBJ=./.object/
PATH_1HDR=./includes/
PATH_2HDR=./srcs/includes2/

# --- 3.Object/Dependencies ---------------------------------------------------

OBJ=$(SRC:%=$(PATH_OBJ)%.o)
DEP=$(OBJ:%.o=%.d)

# --- 4.Rules ------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	-@printf " ===> Creating $(NAME)\n"
	@ar rcs $(NAME) $(OBJ)

$(PATH_OBJ)%.o:%.c
	-@printf " >O $(FLAGS) $*\n"
	@$(CC) $< -o $@

clean:
	-@printf " ===> Removing object file(s)\n"
	@rm -f $(OBJ) $(DEPS)

fclean: clean
	-@printf " ===> Removing $(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
