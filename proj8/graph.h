/* Michael Ziegler                                                   GRAPH_CLASS
 * CSCI 3110-001
 * Project #8
 * Due: 04/23/19
 * File: graph.h
 * Purpose: Graph Class for "proj8" executable.
 */
 
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <limits>  //Infinity

struct PathNode {               // Use to determine shortest path
        double cost;            // Path cost from source vertex to this vertex
        int prev;               // Vertex preceding this vertex in the shortest path
};

struct Edge {                    								// Represents an edge
        int v1, v2;                     						// From vertex, To vertex
        double weight;          								// Edge weight
        Edge(int vertex1, int vertex2, double wt) :             // Edge constructor
				v1{vertex1}, v2{vertex2}, weight{wt} {};        // from, to, weight
};

class Graph
{
public:
        Graph(int);                             // Contructor - Param(s): Number of vertices
        void addEdge(int, int, double, bool);   // Add edge to adjacency list (display as added) - Param(s): From vertex, To vertex, Weight, Directed edge?
        void DijkstraPaths(int);                // Outputs single source shortest paths - Param: source vertex
private:
        int numVertices;                        // Number of vertices in graph
        std::vector<std::list<Edge>> adjacent;  // Adjacency list for vertices
};

#endif
