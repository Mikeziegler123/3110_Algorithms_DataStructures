# Michael Ziegler														MAKEFILE
# CSCI 3110-001
# Project #3
# Due: 02/06/19
#
# Purpose: Makefile for creating "proj3" executable.
CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=ship.cpp cruiseship.cpp cargoship.cpp proj3.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj3

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
