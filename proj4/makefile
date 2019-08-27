# Michael Ziegler                                                       MAKEFILE
# CSCI 3110-001
# Project #4
#Due: 02/28/19
# 
# File: makefile
# Purpose: makefile to create "proj4" executable.
CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=player.cpp deck.cpp card.cpp proj4.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj4

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
