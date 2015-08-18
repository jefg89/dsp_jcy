.PHONY: clean all alsa_slave

CC = gcc
LIB = -lrt -lpthread -lasound -lm -fopenmp -lncurses
APPS = alsa_slave
APPM = alsa_master
SRCS = alsa_slave.c goertzel.c
SRCM = alsa_master.c menu.c
#OBJS = $(SRCS:.c=.o)
#OBJM = $(SRCM:.c=.o)
DEPS = goertzel.h
DEPM = menuGUI.h
all: slave master

slave: $(SRCS) $(DEPS)
	$(CC) -o $(APPS) $(SRCS) $(LIB)
	clear
	@echo "Compilación Exitosa!!" 

master: $(SRCM)	$(DEPM)
	$(CC) -o $(APPM) $(SRCM) $(LIB) -I.
	clear
	@echo "Compilación Exitosa!!" 

clean:
	clear
	rm -f $(OBJS) $(OBJM) $(APPS) $(APPM)
