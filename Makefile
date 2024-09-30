NAME = philo

OBJ = $(SRC:%.c=%.o)

SRC = philosophers.c \
		handling_input.c \
		add_data_to_philo.c \
		create_thread.c \
		eatsleepthink.c \
		print_timings.c \
		death_checker.c \
		free_philo.c 

CFLAGS = -Wall -Werror -Wextra -O3 #-fsanitize=thread

%.o: %.c
	$(CC) $(CFLAGS) -c $^

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
