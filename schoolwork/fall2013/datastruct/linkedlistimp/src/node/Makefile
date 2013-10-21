CFLAGS = -Wall
INC = -I ../../inc
AR = ar
CC = gcc $(CFLAGS) $(INC) 
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
OBJ = $(SRC:.c=.o)
LIB = $(shell /bin/pwd | /bin/sed 's/^.*\///')
all: $(SRC) $(OBJ) lib

debug: CC += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(OBJ) lib

.c.o:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]   %-20s ... " "$<"
	@$(CC) -c $< && echo "OK" || echo "FAIL"
else
	$(CC) -c $<
endif

lib:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[L]   %-20s ... " "$<"
	@$(AR) rcs ../../lib/lib$(LIB).a $(OBJ) && echo "SUCCESS" || echo "FAIL"
else
	$(AR) rcs ../../lib/lib$(LIB).a $(OBJ)
endif


clean:
	rm -f *.o $(OBJ) core
