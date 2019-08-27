/* Michael Ziegler                                          GRAPH_IMPLIMENTATION
 * CSCI 3110-001
 * Project #8
 * Due: 04/23/19
 * 
 * File: graph.cpp
 * Purpose: Graph class implimentation for proj8 executable.
 */
#include <string>
#include <set>
#include "graph.h"

using namespace std;

/*(1)(CONSTRUCTOR)_Purpose:  
*/
Graph::Graph(int V) 
{
	numVertices = V;
	adjacent.resize(numVertices, list<Edge>());
}

/*(2)(ADDEDGE)_Purpose: This function accepts information on an edge, and adds 
 * it's (complete) representation to the adjacency list. Output information on 
 * the edge as it is added to the list.                                       */
void Graph::addEdge(int startVertex, int endVertex, double weight, bool directed) 
{
	Edge edge(startVertex, endVertex, weight);
	
	cout <<  "Edge " << edge.v1 << ", " << edge.v2 << ", " << edge.weight << endl; 
	
	adjacent[edge.v1].push_back(Edge(edge.v1, edge.v2, edge.weight));
	
	if(!directed)
	{
		adjacent[edge.v2].push_back(Edge(edge.v2, edge.v1, edge.weight));
	
		cout << "Edge " << edge.v2 << ", " << edge.v1 << ", " << edge.weight << endl;
	}
}

/*(3)(DIJKSTRASPATHS)_Purpose: This function determines the single-source 
 * shortest path for all vertices in the graph, beginning with the vertex 
 * specified as the argument. It must use a set, to store the cost-so-far for 
 * vertices as they’re discovered (open list). The output for each vertex is its
 * number (zero-based), its total cost from the source vertex, and its preceding
 * vertex (through which theshortest path is obtained).                       */
void Graph::DijkstraPaths(int start)
{
	double infinity = numeric_limits<double>::infinity();

	cout << endl << "Shortest paths:" << endl;

	vector <PathNode> Nodes;
	Nodes.resize(numVertices);	
	
	set<pair<double, int>> openlist;
	
	for (int u = 0; u < numVertices; u++)
	{
		Nodes[u].cost = infinity;
		Nodes[u].prev = -1;
	}
	
	Nodes[start].cost = 0;
	openlist.insert(make_pair(0,start));
	
	while (!openlist.empty())
	{
		pair <double, int> cur;
		cur = *openlist.begin();
		openlist.erase(openlist.begin());

		int v = cur.second;

		for (Edge e : adjacent[v])
		{
			int w = e.v2;
			double weight = e.weight;

			if (Nodes[w].cost > Nodes[v].cost + weight)
			{

				if(Nodes[w].cost != infinity)
				{
					openlist.erase(openlist.find(make_pair(Nodes[w].cost, w)));
				}

				Nodes[w].cost = Nodes[v].cost + weight;
				Nodes[w].prev = e.v1;
				
			    openlist.insert(make_pair(Nodes[w].cost, w));
			}
		}
	}
	
	for(int i = 0; i < numVertices; i++)
	{
		cout << i << " cost: " << Nodes[i].cost << "\tprev: " << Nodes[i].prev << endl;
	}
}
