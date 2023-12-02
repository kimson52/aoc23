SAN_FLAGS = -fsanitize=address,leak,undefined
CFLAGS = -g -Wall -Wextra $(SAN_FLAGS)
OBJS = 1.o utils.o

1: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
.PHONY: clean
clean:
	rm -f *.o 1
