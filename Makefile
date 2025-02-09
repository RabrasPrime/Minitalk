# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/02/10 00:24:56 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

#=-=-=-=-=-=-FILES-=-=-=-=-=-=#

MAKE_DIR    :=  .make/
BUILD_DIR   :=  $(MAKE_DIR)build_$(or $(shell git branch --show-current),default)/
BASE_DIR    :=  normal/

SRC_DIR     =   src/

OBJS_c        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_C))
OBJS_S        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_S))

DEPS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC_C))
DEPS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC_S))

#=-=-=-=-=-=-ROOT-=-=-=-=-=#

SRC_C =   client.c
SRC_S =   server.c

SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c

#=-=-=-=-=-=-INCLUDES-=-=-=-=-=#

LIB_DIR     =   lib/
LIB_PATH    =   libft/libft.a

LIB_PATH    :=  $(addprefix $(LIB_DIR),$(LIB_PATH))
LIB         =   $(patsubst lib%.a, %, $(notdir $(LIB_PATH)))

INC_DIR     =   include/
INCLUDES    =   $(INC_DIR) \
                $(dir $(LIB_PATH))$(INC_DIR)

#=-=-=-=-=-=-COMPIL-=-=-=-=-=#

CC          =   cc

FLAGS       +=  -Wall -Wextra -Werror
PPFLAGS     +=  $(addprefix -I, $(INCLUDES)) -MMD -MP

LDFLAGS     +=  $(addprefix -L, $(dir $(LIB_PATH)))
LDLIB       +=  $(addprefix -l, $(LIB))

AR          =   ar
ARFLAGS     =   -rcs

MAKEFLAG    +=  --no-print-directory

#=-=-=-=-=-=-MODES-=-=-=-=-=#

MODES       :=  debug fsanitize optimize full-optimize

MODES_TRACE :=  $(BUILD_DIR).modes_trace
LAST_MOD    :=  $(shell cat $(MODES_TRACE) 2>/dev/null)

MODE    ?=

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
else ifeq ($(MODE), bonus)
    SRC := $(SRC_BONUS)
    NAME = $(NAME_BONUS)
endif


ifneq ($(LAST_MOD), $(MODE))
$(NAME): force
endif

#=-=-=-=-=-=-CAST-=-=-=-=-=#

.PHONY: all clean fclean $(MODE) re help bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS) $(LDLIB) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(LIB_PATH)
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
	rm -rf $(MAKE_DIR) $(NAME) $(NAME_BONUS)

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