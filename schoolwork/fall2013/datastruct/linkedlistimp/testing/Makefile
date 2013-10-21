CFLAGS = -Wall -L../lib -lstack -llist -lnode
INC = -I ../inc/
CC = gcc $(INC)
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
BIN = $(SRC:.c=)
all: $(SRC) $(BIN)

debug: CC += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN)

.c:
#	make -C ../ clean
#	make -C ../ libs
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]   %-20s ... " "$<"
	@$(CC) -o $@ $< $(CFLAGS) && echo "OK" || echo "FAIL"
else
	$(CC) -o $@ $< $(CFLAGS)
endif

clean:
	rm -f *.o $(BIN) core
