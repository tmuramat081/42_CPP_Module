SUBDIRS := ${wildcard ex*/}

#: Make executable file.
all:
	@for dir in ${SUBDIRS}; do \
	${MAKE} -C $$dir; \
	done

#: Remove all object files.
clean:
	@for dir in ${SUBDIRS}; do \
	${MAKE} -C $$dir clean; \
	done

#: Remove all object and executable files.
fclean:
	@for dir in ${SUBDIRS}; do \
	${MAKE} -C $$dir fclean; \
	done

.PHONY:
	all ${SUBDIRS} clean fclean
