# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2019/03/18 15:30:14 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

# --- 1.Source/Header ----------------------------------------------------------

___PUT=	putchar putchar_fd putendl putendl_fd \
		putnbr putnbr_fd putstr putstr_fd
___MEM=	memcmp memdel bzero memset \
		memcpy memccpy memmove memchr \
		memalloc
__LIST=	lstnew lstdelone lstdel lstadd \
		lstinsert lstappend lstfree lstsize
____TO=	atoi itoa atozu
STRCHR=	strchr strastr strastri strchri \
		strlen wstrlen wcharlen strcmp \
		strncmp strlcmp strnchri strstr \
		strrstr strrchr
STRSET=	strcat strncat strclr strcpy \
		strdel strdup strjoin strnew \
		strsub strsplit strssplit pathjoin \
		free_sarray strtrim
_OTHER=	gnl iswhitespace
_LIBFT=	$(___PUT) $(___MEM) $(__LIST) $(____TO) $(STRCHR) $(STRSET) $(_OTHER)

PRINTF=ft_printf pf_buffer pf_number pf_number_2 pf_other pf_parsing pf_string pf_double pf_string_2
__FTOA=f_bigint f_create_unit f_operand f_create_stack f_free_precision f_putnbr

1ST_HEADER=libft.h
2ND_HEADER=ft_bigint.h ft_printf.h

# --- 2.Path -------------------------------------------------------------------

PATH_1HDR=./includes/
PATH_2HDR=./srcs/includes2/
PATH_OBJ=./obj/
PATH_LIB=./srcs/
PATH_PRINT=./srcs/printf/
PATH_FTOA=./srcs/printf/ftoa/

# --- 3.Object -----------------------------------------------------------------

OBJLIBFT=$(_LIBFT:%=$(PATH_OBJ)ft_%.o)
OBJPRINTF=$(PRINTF:%=$(PATH_OBJ)%.o)
OBJFTOA=$(__FTOA:%=$(PATH_OBJ)%.o)

# --- 4.Variables --------------------------------------------------------------

OPTION_O=-c -I$(PATH_1HDR) -I$(PATH_2HDR)
INCLUDES=$(1ST_HEADER:%=$(PATH_1HDR)%) $(2ND_HEADER:%=$(PATH_2HDR)%)
CC=gcc -Werror -Wall -Wextra -pedantic -g3
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
EOC=\033[0m

# --- 5.Rules ------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJLIBFT) $(OBJPRINTF) $(OBJFTOA)
	@echo "$(YELLOW)Compiling library...$(EOC)"
	@ar rcs $(NAME) $(OBJLIBFT) $(OBJPRINTF) $(OBJFTOA)
	@echo "$(GREEN)Done$(EOC)"

$(PATH_OBJ)%.o:$(PATH_LIB)%.c $(INCLUDES)
	@echo "$(CYAN)Creating $@$(EOC)"
	@$(CC) $(OPTION_O) $< -o $@

$(PATH_OBJ)%.o:$(PATH_PRINT)%.c $(INCLUDES)
	@echo "$(BLUE)Creating $@$(EOC)"
	@$(CC) $(OPTION_O) $< -o $@

$(PATH_OBJ)%.o:$(PATH_FTOA)%.c $(INCLUDES)
	@echo "$(PURPLE)Creating $@$(EOC)"
	@$(CC) $(OPTION_O) $< -o $@

clean:
	@echo "$(YELLOW)Deleting object files...$(EOC)"
	@rm -f $(OBJLIBFT) $(OBJPRINTF) $(OBJFTOA)
	@echo "$(GREEN)Done.$(EOC)"

fclean: clean
	@echo "$(YELLOW)Deleting library...$(EOC)"
	@rm -f $(NAME)
	@echo "$(GREEN)Done$(EOC)"

re: fclean all

.PHONY: all clean fclean re


# --- 6.Unused -----------------------------------------------------------------

#R_LIST=	lstmap lstiter
#R_MATH=	pow sqrt rand
#R___IS=	isalnum isalpha isascii isdigit isprint
#R___TO=	tolower toupper
#RTRCHR=	strstr strnstr strrstr strrchr strcount strequ strnequ
#RTRSET=	strlcat strncpy striter striteri strmap strmapi strtrim
