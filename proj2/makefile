# Michael Ziegler														MAKEFILE
# CSCI 3110-001
# Project #2
# Due: 02/06/19
#
# Purpose: Makefile for creating "proj2.exe".
CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=gaspump.cpp proj2.cpp
#Objects assigned value of sources after substituting every .cpp for .o
OBJECTS=$(SOURCES:.cpp=.o)   
EXECUTABLE=proj2

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
