# Michael Ziegler                                                       MAKEFILE
# CSCI 3110-001
# Project #7
#Due: 03/15/19
# 
# File: makefile
# Purpose: makefile to create "proj7" executable.
CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=card.cpp  proj7.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj7

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
