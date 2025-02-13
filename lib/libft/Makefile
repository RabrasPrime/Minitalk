# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/02/13 11:33:16 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


#=-=-=-=-=-=-FILES-=-=-=-=-=-=#

MAKE_DIR    :=  .make/
BUILD_DIR   :=  $(MAKE_DIR)build_$(or $(shell git branch --show-current),default)/
BASE_DIR    :=  normal/

SRC_DIR     =   src/

OBJS        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))
DEPS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC))

#=-=-=-=-=-=-ROOT-=-=-=-=-=#

SRC	=

#=-=-=-=-=-=-IS-=-=-=-=-=#

SRC	+= $(addprefix $(IS_DIR), $(IS_SRC))

IS_DIR	=	is/
IS_SRC	=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \

#=-=-=-=-=-=-LST-=-=-=-=-=#

SRC	+=	$(addprefix $(LST_DIR), $(LST_SRC))

LST_DIR	=	lst/
LST_SRC	=	ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \

#=-=-=-=-=-=-MEM-=-=-=-=-=#

SRC	+=	$(addprefix $(MEM_DIR), $(MEM_SRC))

MEM_DIR =	mem/
MEM_SRC =	ft_bzero.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_calloc.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_realloc.c \

#=-=-=-=-=-=-GNL-=-=-=-=-=#

SRC	+=	$(addprefix $(GNL_DIR), $(GNL_SRC))


GNL_DIR +=	get_next_line/
GNL_SRC +=	get_next_line_utils.c \
			get_next_line.c \

#=-=-=-=-=-=-PRINTF-=-=-=-=-=#

SRC	+=	$(addprefix $(PRINTF_DIR), $(PRINTF_SRC))

PRINTF_DIR	=	printf/
PRINTF_SRC	=	ft_char.c \
				ft_integer.c \
				ft_printf.c \
				ft_printstr.c \
				ft_unsigned.c \
				ft_hexa.c \
				ft_pointer.c \
				ft_printflen.c \
				ft_str.c \
				ft_utils.c \

#=-=-=-=-=-=-PUT-=-=-=-=-=#

SRC	+=	$(addprefix $(PUT_DIR), $(PUT_SRC))

PUT_DIR	=	put/
PUT_SRC	=	ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \

#=-=-=-=-=-=-STRINT-=-=-=-=-=#

SRC	+=	$(addprefix $(STRINT_DIR), $(STRINT_SRC))

STRINT_DIR	=	strint/
STRINT_SRC	=	ft_atoi.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strnstr.c \
				ft_itoa.c \
				ft_striteri.c \
				ft_strlen.c \
				ft_strrchr.c \
				ft_split.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strncmp.c \
				ft_substr.c \
				ft_swap.c \
				ft_freestr.c \
				ft_tablen.c \
				ft_array_size.c \
				ft_free_array.c \

#=-=-=-=-=-=-TO-=-=-=-=-=#

SRC	+=	$(addprefix $(INTO_DIR), $(INTO_SRC))

INTO_DIR	=	into/
INTO_SRC	=	ft_tolower.c \
				ft_toupper.c \

#=-=-=-=-=-=-ERROR-=-=-=-=-=#

SRC	+=	$(addprefix $(ERROR_DIR), $(ERROR_SRC))

ERROR_DIR	=	error/
ERROR_SRC	=	ft_error.c \

#=-=-=-=-=-=-INCLUDES-=-=-=-=-=#

LIB_DIR		=
LIB_PATH	=
LIB_PATH	:=	$(addprefix $(LIB_DIR),$(LIB_PATH))
LIB			=	$(patsubst lib%.a, %, $(notdir $(LIB_PATH)))

INC_DIR		=	include/
INCLUDES	=	$(INC_DIR) \
				$(dir $(LIB_PATH))$(INC_DIR)
			
#=-=-=-=-=-=-COMPIL-=-=-=-=-=#

CC			=	cc

FLAGS		+=	-Wall -Wextra -Werror
PPFLAGS		+=	$(addprefix -I, $(INCLUDES)) -MMD -MP

LDFLAGS		+=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIB		+=	$(addprefix -l, $(LIB))

AR			=	ar
ARFLAF		=	-rcs

MAKEFLAG	+=	--no-print-directory

#=-=-=-=-=-=-MODES-=-=-=-=-=#

MODES		:=	debug fsanitize optimize full-optimize

MODES_TRACE	:=	$(BUILD_DIR).modes_trace
LAST_MOD	:= $(shell cat $(MODES_TRACE) 2>/dev/null)

MODE	?=

ifneq ($(MODE), )
	BUILD_DIR := $(BUILD_DIR)$(MODE)/
else
	BUILD_DIR := $(BUILD_DIR)$(BASE_BUILD_DIR)
endif

ifeq ($(MODE), debug)
	FLAGS = -g3
else ifeq ($(MODE), fsanitize)
	FLAGS = -g3 -fsanitize=address
else ifeq ($(MODE), optimize)
	FLAGS += -O2
else ifeq ($(MODE), full-optimize)
	FLAGS += -O3
else ifneq ($(MODE),)
	ERROR = MODE
endif

ifneq ($(LAST_MOD), $(MODE))
$(NAME): force
endif

#=-=-=-=-=-=-CAST-=-=-=-=-=#

.PHONY: all clean fclean $(MODE) re help

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(MODE) > $(MODES_TRACE)
	$(AR) $(ARFLAF) $(NAME) $(OBJS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(PPFLAGS) $(FLAGS) -c $< -o $@

$(LIB_PATH): force
	@$(MAKE) -C $(@D)


.PHONY: clean
clean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY: re
re: fclean
	$(MAKE)

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all       Build the project"
	@echo "  clean     Remove object files and dependencies"
	@echo "  fclean    Remove all build files, binary, and mode trace"
	@echo "  re        Clean and rebuild"

.PHONY: print-%
print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY: force
force:

-include $(DEPS)

.DEFAULT_GOAL := all