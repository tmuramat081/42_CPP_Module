NAME := a.out
CC := c++
CFLAGS := -std=c++98 -pedantic

SRCS := main.cpp Controller.cpp PhoneBook.cpp Contact.cpp
OBJS := ${SRCS:.cpp=.o}
INCS := -I.

# Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K
MOVE := \033[1F
CR := \033[1G

# Commands
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${INCS} ${OBJS} -o $@
	@echo "${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

#: Make executable file.
all: ${NAME}

#: Remove all object files.
clean:
	@${RM} ${OBJS} ${DEPS}
	@${PRINTF} "${RED}Cleaned up object files in ${basename ${NAME}} ${DEFAULT}\n"

#: Remove all object and executable files.
fclean:	clean
	@${RM} ${NAME}
	@${PRINTF} "${RED}Removed object and executable files in ${NAME} ${DEFAULT}\n"

#: Remove and recompile all.
re: fclean
	@${MAKE} -s all

.PHONY:
	all clean fclean re run dev git norm nm help

