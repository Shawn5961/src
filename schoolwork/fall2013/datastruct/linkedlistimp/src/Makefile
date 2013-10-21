# Makefile for Backgammon project
SHELL = /bin/bash -e
CC = g++ $(CFLAGS) $(OPTS) $(INC)
INC = -I ../include/
CFLAGS = -Wall 
OBJ = $(shell find . -name *.o)
OPTS =
PARTS = $(shell /bin/ls -1Ad * | grep -v 'Makefile')
AR = ar
DEBUG = 
default: libs

debug: CC += -DDEBUG -g
debug: DEBUG = debug
debug: libs

libs:
	@for i in $(PARTS); do make -C $$i $(DEBUG); echo; done
	@echo

clean:
	@for i in $(PARTS); do make -C $$i clean; done
	@rm -f ${LIB}
