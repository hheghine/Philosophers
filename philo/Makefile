NAME			= philo

PURPLE			:= \033[0;34m
PINK			:= \033[0;35m
RESET			:= \033[0m

SRC_DIR 		= src
SRCS			= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard includes/*.h)
OBJ_DIR			= obj
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
INCS			= -Iincludes
CC				= cc 
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=thread
MK				= mkdir -p

PRINTF			= printf

PRINTF			= printf

TOTAL_SRC	:= $(shell expr $(shell echo -n $(SRCS) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
# ensures that division by zero errors are avoided when calculating the percentage of source files processed 
ifeq ($(shell test $(TOTAL_SRC) -le 0; echo $$?),0)
	TOTAL_SRC := $(shell echo -n $(SRCS) | wc -w)
endif
CURRENT_SRC	:= 0
SRC_PCT		= $(shell expr 100 \* $(CURRENT_SRC) / $(TOTAL_SRC))


all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile | $(OBJ_DIR)
	@$(eval CURRENT_SRC = $(shell expr $(CURRENT_SRC) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(PURPLE)$<$(RESET)..." "" $(CURRENT_SRC) $(TOTAL_SRC) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(INCS)$(MINILIBX) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) > /dev/null 2>&1
	@$(PRINTF) "\r%100s\r$(PINK)✧ $(PURPLE)Philo $(PINK)successfully compiled! ✧$(RESET)\n"

clean:			
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)
				@$(PRINTF) "$(PINK)✧ $(PURPLE)Philo $(PINK)successfully cleaned! ✧$(RESET)\n"
				
re:				fclean all

.PHONY:			all clean fclean re bonus