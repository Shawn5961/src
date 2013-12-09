SHELL = /bin/bash -e
INC = -I inc/
CXXFLAGS = -Wall 
OPTS =
CXX = g++ $(CXXFLAGS) $(OPTS) $(INC)
OBJ = 
AR = ar
DEBUG = 
LIBS = src
UNIT = testing
ALL = $(LIBS) testing
BIN = 
default: libs testing
debug: libs-debug testing-debug

libs-debug: CXX += -DDEBUG -g
libs-debug: DEBUG = debug
libs-debug: libs

libs:
	@for i in $(LIBS); do make -C $$i $(DEBUG); echo; done
	@echo

testing-debug: CXX += -DDEBUG -g
testing-debug: DEBUG = debug
testing-debug: testing

testing:
	@for i in $(UNIT); do make -C $$i $(DEBUG); echo; done
	@echo

clean:
	@for i in $(ALL); do make -C $$i clean; done
	@rm -f lib/*
