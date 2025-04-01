NAME = push_swap

SRCS = main.c \
		push.c reverse_rotate.c \
		split.c rotate.c sort_three.c \
		stack.c start.c utils.c swap.c sort_five.c errors.c

INCLUDE = ./push_swap.h

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS} $(INCLUDE)
	@${CC} ${SRCS} -o ${NAME}
	@echo "\n Created $(NAME) ✓\n"

clean:
			@${RM} ${OBJS}
			@echo "\n ◎ All objects cleaned successfully ◎\n"

fclean: 
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@echo "\n ◎ All objects and executable cleaned successfully ◎\n"

re: fclean all

.PHONY: all clean fclean re