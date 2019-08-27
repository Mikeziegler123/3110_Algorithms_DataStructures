# Michael Ziegler                                                       MAKEFILE
# CSCI 3110-001
# Project #
#Due: 03/18/19
# 
# File: makefile
# Purpose: makefile to create "proj5" executable.
CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=maze.cpp proj5.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj5

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
