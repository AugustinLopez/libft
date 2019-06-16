# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2019/06/16 13:15:14 by aulopez          ###   ########.fr        #
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

# --- 4.Variables --------------------------------------------------------------

CC_DEBUG=-pedantic -g3
CC=gcc -Werror -Wall -Wextra $(CC_DEBUG) -c -I$(PATH_1HDR) -I$(PATH_2HDR)
INCLUDES=$(1ST_HEADER:%=$(PATH_1HDR)%) $(2ND_HEADER:%=$(PATH_2HDR)%)

# Text Style
BOLD=\033[1m
_DIM=\033[2m
ITAL=\033[3m
UNDR=\033[4m
INVR=\033[7m
HIDE=\033[8m
STRK=\033[9m
RST_A=\033[0m
RST_B=\033[21m
RST_D=\033[22m
RST_U=\033[24m
RST_I=\033[27m
RST_H=\033[28m
RST_S=\033[29m

# Foreground Color
RST_FG=\033[39m
FG_BLA=\033[30m
FG_RED=\033[31m
FG_GRE=\033[32m
FG_YEL=\033[33m
FG_BLU=\033[34m
FG_PUR=\033[35m
FG_CYA=\033[36m
FG_WHI=\033[97m
FG_LGRA=\033[37m
FG_DGRA=\033[90m
FG_LRED=\033[91m
FG_LGRE=\033[92m
FG_LYEL=\033[93m
FG_LBLU=\033[94m
FG_LPUR=\033[95m
FG_LCYA=\033[96m

# Background Color
RST_BG=\033[49m
BG_BLA=\033[40m
BG_RED=\033[41m
BG_GRE=\033[42m
BG_YEL=\033[43m
BG_BLU=\033[44m
BG_PUR=\033[45m
BG_CYA=\033[46m
BG_WHI=\033[107m
BG_LGRA=\033[47m
BG_DGRA=\033[100m
BG_LRED=\033[101m
BG_LGRE=\033[102m
BG_LYEL=\033[103m
BG_LBLU=\033[104m
BG_LPUR=\033[105m
BG_LCYA=\033[106m

# --- 5.Rules ------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n$(FG_LYEL)Object files creation:   $(FG_GRE)$(BOLD)Done.$(RST_A)  \n"
	@ar rcs $(NAME) $(OBJ)
	@printf "$(FG_LYEL)Compiling library:       $(FG_GRE)$(BOLD)Done.$(RST_A)\n"

$(PATH_OBJ)%.o:$(PATH_LIB)%.c $(INCLUDES)
	@printf "$(FG_YEL).$(RST_A)"
	@$(CC) $< -o $@

$(PATH_OBJ)%.o:$(PATH_PRINT)%.c $(INCLUDES)
	@printf "$(FG_LGRE).$(RST_A)"
	@$(CC) $< -o $@

$(PATH_OBJ)%.o:$(PATH_FTOA)%.c $(INCLUDES)
	@printf "$(FG_GRE).$(RST_A)"
	@$(CC) $< -o $@

clean:
	@rm -f $(OBJ)
	@printf "$(FG_LRED)Deleting object files:   $(FG_GRE)$(BOLD)Done.$(RST_A)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(FG_LRED)Removing library:        $(FG_GRE)$(BOLD)Done.$(RST_A)\n"

re: fclean all

.PHONY: all clean fclean re
