/* Michael Ziegler                                              	  MAZE_CLASS
 * CSCI 3110-001
 * Project #5
 * Due: 03/18/19
 * 
 * File: maze.h
 * Purpose: Declaration of the "Maze" class.
 */

#ifndef MAZE_H
#define MAZE_H
#include <fstream> 

 
class Maze								// Represents Maze class' data and function members
{ 
public: 
	Maze(std::ifstream&);				// Constructor: takes file object and reads maze map from file
	void Print();						// Displays the maze and its state
	void FindExit(int, int, bool&);		// Recursive function that finds the exit (ints: row, then column)
private: 
	char maze[10][10];					// 2D array that holds maze - outer columns and rows not traversable
	int maxRows; 						// Maximum number of rows - excludes outer walls
	int maxCols; 						// Maximum number of columns - excludes outer walls
};

#endif
