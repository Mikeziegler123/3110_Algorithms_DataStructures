/* Michael Ziegler                                           MAZE_IMPLIMENTATION
 * CSCI 3110-001
 * Project #5
 * Due: 03/18/19
 * 
 * File: maze.cpp
 * Purpose: Definition of the "Maze" Class Functions.
 */
#include "maze.h"
#include <iostream>
#include <algorithm>

/*(1)_CONSTRUCTOR_: Purpose:
																			  */
Maze::Maze(std::ifstream& myin)
{
	myin >> maxRows;
	myin >> maxCols;
	
	for (int i = 0; i <= (maxRows + 1); i++)
	{
		for (int j = 0; j <= (maxCols + 1); j++)
		{
			maze[i][j] = 'X';
		}
	}

	for (int i = 1; i <= maxRows; i++)
	{
		for (int j = 1; j <= maxCols; j++)
		{
			myin >> maze[i][j];
		}
	}
}

/*(2)_PRINT()_: Purpose:
																			  */
void Maze::Print()
{
	std::cout << "Maze State:" << std::endl;
	for (int i = 1; i <= maxRows; i++)
	{
		for (int j = 1; j <= maxCols; j++)
		{
			std::cout << " " << maze[i][j];
		}
		std::cout << std::endl;
	}
	return;
}

/*(3)_FINDEXIT()_: Purpose:
																			  */
void Maze::FindExit(int x, int y, bool& exit)
{

	if (maze[x][y] == 'O')
	{
		maze[x][y] = '*';
		std::cout << "Exploring: " << x << "," << y << std::endl;

		Print();
		
		/*Check North   */
			FindExit(x, y+1, exit);
		/*Check East   */
			FindExit(x+1, y, exit);
		/*Check South   */
			FindExit(x-1, y, exit);
		/*Check West   */
			FindExit(x, y-1, exit);
	}
	else if(maze[x][y] == 'E')
		std::cout << "Exploring: " << x << "," << y << std::endl;
		exit = true;
}
