CFLAGS = -Wall ../src/*.o
INC = -I ../inc
CXX = g++ $(INC)
SRC = $(shell /bin/ls -1 *.cpp 2>/dev/null)
BIN = $(SRC:.cpp=)
all: $(SRC) $(BIN)

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN)

.cpp:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]   %-20s ... " "$<"
	@$(CXX) -o $@ $< $(CFLAGS) && echo "OK" || echo "FAIL"
else
	$(CXX) -o $@ $< $(CFLAGS)
endif

clean:
	rm -f *.o $(BIN) core
