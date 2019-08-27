# Michael Ziegler                                                       MAKEFILE
# CSCI 3110-001
# Project #8
#Due: 04/23/19
# 
# File: makefile
# Purpose: makefile to create "proj8" executable.
CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=graph.cpp  proj8.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj8

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
