# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2019/08/01 20:06:35 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
COMPILER=gcc
FLAGS=-Wall -Wextra -Werror
CC=gcc $(FLAGS) -c -I$(PATH_1HDR) -I$(PATH_2HDR)

# --- 1.Source/Header ----------------------------------------------------------

_PUT=	putchar \
		putchar_fd \
		putendl \
		putendl_fd \
		putnbr \
		putnbr_fd \
		putstr \
		putstr_fd
_MEM=	memdel \
		bzero \
		memset \
		memcpy \
		memccpy \
		memmove \
		memchr \
		memalloc \
		memcmp
_LIST=	lstnew \
		lstdelone \
		lstdel \
		lstadd \
		lstmap \
		lstccpy \
		lstiter \
		lstinsert \
		lstappend \
		lstfree \
		lstsize
_IS=	isalpha \
		isdigit \
		isalnum \
		isascii \
		isprint \
		iswhitespace
_TO=	atoi \
		toupper \
		tolower \
		itoa \
		atozu
STRCHR=	strchr \
		strcmp \
		strncmp \
		strstr \
		strnstr \
		strequ \
		strnequ \
		strastr \
		strastri \
		strchri \
		strlen \
		wstrlen \
		wcharlen \
		strcmp \
		strlcmp \
		strnchri \
		strrstr \
		strrchr
STRSET=	strcat \
		strncat \
		strlcat \
		strclr \
		strcpy \
		strncpy \
		strdel \
		strdup \
		strjoin \
		strnew \
		strsub \
		strtrim \
		striter \
		striteri \
		strmap \
		strmapi \
		pathjoin \
		free_sarray
_PARSE=	strsplit \
		strssplit \
		gnl \
		flagarg
_MATH=abs
_LIBFT=	$(_PUT) $(_MEM) $(_LIST) $(_IS) $(_TO) $(STRCHR) $(STRSET) $(_PARSE) $(_MATH)

PRINTF=	ft_printf \
		pf_buffer \
		pf_number \
		pf_number_2 \
		pf_other \
		pf_parsing \
		pf_string \
		pf_double \
		pf_string_2
_FTOA=	f_bigint \
		f_create_unit \
		f_operand \
		f_create_stack \
		f_free_precision \
		f_putnbr \

1ST_HEADER=	libft.h
2ND_HEADER=	ft_bigint.h \
			ft_printf.h

# --- 2.Path -------------------------------------------------------------------

PATH_1HDR=./includes/
PATH_OBJ=./obj/
PATH_LIB=./srcs/
PATH_2HDR=./srcs/includes2/
PATH_PRINT=./srcs/printf/
PATH_FTOA=./srcs/printf/ftoa/

# --- 3.Object -----------------------------------------------------------------

OBJLIBFT=$(_LIBFT:%=$(PATH_OBJ)ft_%.o)
OBJPRINTF=$(PRINTF:%=$(PATH_OBJ)%.o)
OBJFTOA=$(_FTOA:%=$(PATH_OBJ)%.o)
OBJ=$(OBJLIBFT) $(OBJPRINTF) $(OBJFTOA)
INCLUDES=$(1ST_HEADER:%=$(PATH_1HDR)%) $(2ND_HEADER:%=$(PATH_2HDR)%)

# --- 4.Rules ------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	-@printf " ==> Creating $(NAME)\n"
	@ar rcs $(NAME) $(OBJ)

$(PATH_OBJ)%.o:$(PATH_LIB)%.c $(INCLUDES)
	-@printf " >O $(FLAGS) $(@:obj/%.o=%)\n"
	@$(CC) $< -o $@

$(PATH_OBJ)%.o:$(PATH_PRINT)%.c $(INCLUDES)
	-@printf " >O $(FLAGS) $(@:obj/%.o=%)\n"
	@$(CC) $< -o $@

$(PATH_OBJ)%.o:$(PATH_FTOA)%.c $(INCLUDES)
	-@printf " >O $(FLAGS) $(@:obj/%.o=%)\n"
	@$(CC) $< -o $@

clean:
	-@printf " ===> Removing object file(s)\n"
	@rm -f $(OBJ)

fclean: clean
	-@printf " ===> Removing $(NAME)\n"
	@rm -f $(NAME)

re: fclean all

O3: FLAGS += -O3 -fno-builtin
O3: re;
O2: FLAGS += -O2
O2: re;
Os: FLAGS += -Os
Os: re;
g3: FLAGS = -g3
g3: re;
pedantic: FLAGS += -pedantic
pedantic: re;

.PHONY: all clean fclean re O3 O2 Os g3 pedantic
