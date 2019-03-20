# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2019/03/20 12:31:44 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

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
		gnl
_LIBFT=	$(_PUT) $(_MEM) $(_LIST) $(_IS) $(_TO) $(STRCHR) $(STRSET) $(_OTHER)

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

# --- 4.Variables --------------------------------------------------------------

CC=gcc -Werror -Wall -Wextra -pedantic -g3 -c -I$(PATH_1HDR) -I$(PATH_2HDR)
INCLUDES=$(1ST_HEADER:%=$(PATH_1HDR)%) $(2ND_HEADER:%=$(PATH_2HDR)%)

BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m
EOC=\033[0m
BOLD=\033[1m
ITALIC=\033[3m
UNDER=\033[4m
STRIKE=\033[9m

# --- 5.Rules ------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\r$(YELLOW)Object file creation:     $(GREEN)$(BOLD)Done.$(EOC)\n"
	@printf "\r$(YELLOW)Compiling library: $(EOC)       "
	@ar rcs $(NAME) $(OBJ)
	@printf "$(GREEN)$(BOLD)Done.$(EOC)\n"

$(PATH_OBJ)%.o:$(PATH_LIB)%.c $(INCLUDES)
	@printf "\r$(PURPLE)$(ITALIC)Creating %-22s$(EOC)" "$@$ "
	@$(CC) $< -o $@

$(PATH_OBJ)%.o:$(PATH_PRINT)%.c $(INCLUDES)
	@printf "\r$(BLUE)$(ITALIC)Creating %-22s$(EOC)" "$@$ "
	@$(CC) $< -o $@

$(PATH_OBJ)%.o:$(PATH_FTOA)%.c $(INCLUDES)
	@printf "\r$(BLUE)$(ITALIC)Creating %-22s$(EOC)" "$@$ "
	@$(CC) $< -o $@

clean:
	@printf "$(YELLOW)Deleting object files: $(EOC)   "
	@rm -f $(OBJ)
	@printf "$(GREEN)$(BOLD)Done.$(EOC)\n"

fclean: clean
	@printf "$(YELLOW)Removing library: $(EOC)        "
	@rm -f $(NAME)
	@printf "$(GREEN)$(BOLD)Done.$(EOC)\n"

re: fclean all

.PHONY: all clean fclean re


# --- 6.Unused -----------------------------------------------------------------

#R_LIST=	lstmap lstiter
#R_MATH=	pow sqrt rand
#R___IS=	isalnum isalpha isascii isdigit isprint
#R___TO=	tolower toupper
#RTRCHR=	strnstr strcount strequ strnequ
#RTRSET=	strlcat strncpy striter striteri strmap strmapi
