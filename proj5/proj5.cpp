/* Michael Ziegler                                                DRIVER_PROGRAM
 * CSCI 3110-001
 * Project #5
 * Due: 03/18/19
 * 
 * File: proj5.cpp
 * Purpose: Write a C++ program that, given a starting point, finds its way out
 * of a maze, using recursion. The maze’s map will be read from a file at the 
 * start of the program. Your code must work for all legal mazes. The maze is a 
 * rectangular grid represented as a 2D standard C++ array, and the exit (if 
 * there is one) is on an outer row or column of the play area (nonred cells 
 * below). The program should run until the exit to the maze is found or until 
 * it determines that there is no exit(after exploring all traversable/navigable 
 * cells). Exploration of the maze is done by recursively invoking a function 
 * and marking the cells visited with a special character (an electronic bread 
 * crumb to keep from reprocessing explored cells). The legal moves are to cells
 * adjacent to the current cell, but not diagonal to it. The order in which 
 * adjacent cells must be explored is given below. The maze should be solved 
 * through recursive calls and backtracking, and not by looking ahead(you do not
 * have the ability to “look” into neighboring cells before moving – you simply
 * move and rely on backtracking if it’s a “bad” move). If the specially marked 
 * exit cell is encountered the game should print a message that the exit was
 * found. Otherwise, after exploring the whole maze, a message is output stating
 * that there is no exit.
 */
#include <iostream>
#include <fstream>
#include "maze.h"

int main()
{
	bool exit = false;
	int sX = 1;
	int sY = 1;
	std::ifstream myin;
	myin.open("maze.txt", std::ifstream::in);

	Maze maze = Maze(myin);
	
	maze.Print();
	
	std::cout << "Start position: " << sX << "," << sY << std::endl;
	
	maze.FindExit(sX, sY, exit);

	if (exit == true)
		std::cout << "Found Exit!" << std::endl;
	else
		std::cout << "No exit." << std::endl;


	myin.close();

	return 0;
}
