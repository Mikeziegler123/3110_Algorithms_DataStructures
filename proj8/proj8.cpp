/* Michael Ziegler                                                DRIVER_PROGRAM
 * CSCI 3110-001
 * Project #8
 * Due: 04/23/19
 * 
 * File: proj8.cpp
 * Purpose:Reads an input file named graph.txt that contains a graph: the graph
 * may be undirected, or it may bedirected (your code must handle both). It is 
 * represented in the file by:o A header line containing three (3) integers: The 
 * first integer is the number of vertices in the graph (minimum of 3 vertices
 * for each graph); the second is the number of edge records that follow the
 * header line; the third is the starting vertex for the single source shortest
 * paths computation. o Each edge record consists of: two integers representing
 * a “From” vertex and a “To” vertex;a double for the edge’s weight or cost; and
 * a string with either value “true” or value “false” (case sensitive) that 
 * indicates whether the edge is directed (true) or not (false). 
 * Note the following regarding edge records:  Vertices are numbered from 0 to 
 * number of vertices minus 1. Directed edge records begin with “From” vertex,
 * and present each “To” vertex in order for each vertex: all edges (if any) 
 * from vertex 0 to other vertices are presented in order, then all edges (if 
 * any) from vertex 1 to other vertices in order, etc. 
 *
 * --> Undirected edges are only presented once. An edge between vertex 1 and 
 * vertex 3 is shown once(even though its representation must be bidirectional).
 *
 * --> Instantiate the graph object by invoking the single argument constructor 
 * (with the number of vertices).
 * 
 * --> Call addEdge once for each edge read from the file.
 * 
 * --> Invoke DijkstraPaths with the starting vertex read from the file.      */
 
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "graph.h"

using namespace std;

int main()
{

	int numVertices,numEdges, vertex;
	int from = 0;
	int to = 0;
	double cost = 0;  
	bool tf;
	string tF;
	
    ifstream graphIn;
	graphIn.open("graph.txt");

	graphIn >> numVertices;
	graphIn >> numEdges;
	graphIn >> vertex;

	Graph graph(numVertices);


	for (int i = 0;i<numEdges; i++)
	{
		graphIn >> from;
		graphIn >> to;
		graphIn >> cost;
		graphIn >> tF;
		
		istringstream(tF) >> std::boolalpha >> tf;
		graph.addEdge(from, to, cost, tf);
	}
	graph.DijkstraPaths(vertex);
	
return 0;
}
