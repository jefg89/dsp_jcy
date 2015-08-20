.PHONY: clean all dtmf

CC = gcc
LIB = -lrt -lpthread -lasound -lm -fopenmp -lncurses
SRCS =  dtmf.c menu.c goertzel.c
DEPS = goertzel.h menuGUI.h
APP = dtmf

all:  dtmf

dtmf: $(SRCS) $(DEPS)
	$(CC) -o $(APP) $(SRCS) $(LIB) -I.
	clear
	@echo "Compilación Exitosa!!" 

clean:
	clear
	rm -f  $(APP)  
