NAME := a.out
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := megaphone.cpp
OBJS := ${SRCS:.cpp=.o}
INCS :=

# Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K

# Commands
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${INCS} ${OBJS} -o $@
	@echo "${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

%.o: %.c
	@${CC} ${CFLAGS} ${INCS} -c $< -o $@

#: Make executable file.
all: ${NAME}

#: Remove all object files.
clean:
	@${RM} ${OBJS}
	@${PRINTF} "${RED}Cleaned up object files in ${NAME} ${DEFAULT}\n"

#: Remove all object and executable files.
fclean:	clean
	@${RM} ${NAME}
	@${PRINTF} "${RED}Removed object and executable files in ${NAME} ${DEFAULT}\n"

#: Remove and recompile all.
re: fclean

.PHONY:
	all clean fclean re run dev git norm nm help

