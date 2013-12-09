CFLAGS = -Wall
INC = -I ../inc
AR = ar
CXX = g++ $(CFLAGS) $(INC) 
SRC = $(shell /bin/ls -1 *.cpp 2>/dev/null)
OBJ = $(SRC:.cpp=.o)
all: $(SRC) $(OBJ)

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(OBJ)

.cpp.o:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]   %-20s ... " "$<"
	@$(CXX) -c $< && echo "OK" || echo "FAIL"
else
	$(CXX) -c $<
endif

clean:
	rm -f *.o $(OBJ) core
