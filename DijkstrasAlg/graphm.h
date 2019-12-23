// file graphm.h
// header file for class GraphM

#ifndef GRAPHM_H
#define GRAPHM_H

#include "nodedata.h"
#include <limits>

//---------------------------------------------------------------------------
// BinTree class: defined as graph class capable of finding the shortest path
//                between two points
//   - Utilizes Dijkstra's algorithm to find the shortest path between two
//     points
//   - Capable of adding an edge to the graph from one point to another
//   - Capable of removing an edge from the graph from one point to another
//   - Capable of displaying the shortest path between every edge
//   - Capable of displaying the shortest path of one edge pair
//   - Capable of building a graph from an input file
//
// Implementation and assumptions:
//   -- The data array, cost/adjacency matrix, and TableType array is
//      initialized to 101 nodes.
//   -- We begin use of these different arrays at element 1, ignoring element 0
//      so as to reduce confusion as we build graphs that use one-based
//      indexing.
//   -- Assuming that the input file is formatted correctly (3 ints on one line
//      for an edge, etc.).
//   -- Cost matrix holds the cost of travelling from one node to another. For
//   -- edges from one node to another that do not exist the cost is initialized
//      to infinity.
//   -- TableType matrix holds data on if the node was visited, its cost from
//      its origin node to the endpoint, as well as the previous node in the
//      current nodes path to the endpoint. Visited is initialized to false,
//      distance is initialized to infinity and path is initialized to 0.
//   -- Size is initialized to 0 and is eventually set to the number of nodes
//      in the graph.
//   -- Break reading from the text file when 0 is passed in.
//---------------------------------------------------------------------------

const int MAXNODES = 101; // global constant for max number of nodes
// global constant for positive infinity
const int INFINITY = std::numeric_limits<int>::max();

class GraphM {
public:
    GraphM(); // GraphM constructor
    void buildGraph(istream&); // builds the graph from input file
    // inserts edge into graph
    void insertEdge(int fromNode, int toNode, int value);
    void removeEdge(int fromNode, int toNode); // removes edge from graph
    // finds the shortest path from every node to every other node if a path
    // exists
    void findShortestPath();
    // displays the value of every node to every another node as well as
    // the shortest path between these nodes
    void displayAll() const;
    void display(int, int) const; // display the shortest path between two nodes

private:
    struct TableType {
        bool visited; // whether node has been visited
        int dist; // currently known shortest distance from source
        int path; // previous node in path of min dist
    };
    NodeData data[MAXNODES]; // data for graph nodes information
    int C[MAXNODES][MAXNODES]; // cost array, the adjacency matrix
    int size; // number of nodes in the graph
    TableType T[MAXNODES][MAXNODES]; // stores visited, distance, path
    // helper method for display and displayAll
    void displayHelper(int, int) const;
    void locationHelper(int, int) const; // helper method for display
    void makeEmpty(); // assists in clearing T matrix before call to Dijkstra's
};

#endif //GRAPHM_H
