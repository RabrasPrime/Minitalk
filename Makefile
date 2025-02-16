# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/02/16 23:48:31 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_CLT = client

NAME_SRV = server

#=-=-=-=-=-=-FILES-=-=-=-=-=-=#

MAKE_DIR    :=  .make/
BUILD_DIR   :=  $(MAKE_DIR)build_$(or $(shell git branch --show-current),default)/
BASE_DIR    :=  normal/

SRC_DIR     =   src/

OBJS_C        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_C))
OBJS_S        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_S))

OBJS_BONUS_C        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_BONUS_C))
OBJS_BONUS_S        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_BONUS_S))

DEPS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC_C))
DEPS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC_S))

DEPS_BONUS       =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC_BONUS_C))
DEPS_BONUS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC_BONUS_S))

#=-=-=-=-=-=-ROOT-=-=-=-=-=#

SRC_C =   client.c minitalk.c
SRC_S =   server.c minitalk.c

SRC_BONUS_C = client_bonus.c minitalk.c
SRC_BONUS_S = server_bonus.c minitalk.c

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
endif


ifneq ($(LAST_MOD), $(MODE))
$(NAME): force
endif

#=-=-=-=-=-=-CAST-=-=-=-=-=#

.PHONY: all clean fclean $(MODE) re help bonus

all: client server

client: $(OBJS_C) $(LIB_PATH)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(FLAGS) $(OBJS_C) $(LDFLAGS) $(LDLIB) -o $(NAME_CLT)

server: $(OBJS_S) $(LIB_PATH)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(FLAGS) $(OBJS_S) $(LDFLAGS) $(LDLIB) -o $(NAME_SRV)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(LIB_PATH)
	@mkdir -p $(@D)
	$(CC) $(PPFLAGS) $(FLAGS) -c $< -o $@

$(LIB_PATH): force
	@$(MAKE) -C $(@D)

bonus: server_bonus client_bonus

client_bonus: $(OBJS_BONUS_C) $(LIB_PATH)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(FLAGS) $(OBJS_BONUS_C) $(LDFLAGS) $(LDLIB) -o $(NAME_CLT)

server_bonus: $(OBJS_BONUS_S) $(LIB_PATH)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(FLAGS) $(OBJS_BONUS_S) $(LDFLAGS) $(LDLIB) -o $(NAME_SRV)

.PHONY: clean
clean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR) $(NAME) $(NAME_BONUS) $(NAME_CLT) $(NAME_SRV)

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
-include $(DEPS_BONUS)

.DEFAULT_GOAL := all