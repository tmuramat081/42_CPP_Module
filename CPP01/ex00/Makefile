NAME := a.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS := ${SRCS:.cpp=.o}


# Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m

# Commands
${NAME}: ${OBJS}
	@${CXX} ${CXXFLAGS} ${OBJS} -o $@
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

