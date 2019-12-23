// file graphl.h
// header file for class GraphL

#ifndef GRAPHL_H
#define GRAPHL_H

#include "nodedata.h"

//---------------------------------------------------------------------------
// BinTree class: defined as graph class capable of performing depth first
//                search
//   - Utilizes depth first search to traverse through the graph
//   - Capable of displaying the edges and node data of the graph
//   - Capable of deleting the graph
//
// Implementation and assumptions:
//   -- Graph is set to a size of 101, or MAXNODES_L.
//   -- Insert EdgeNodes into beginning of adjacency list as they come in from
//      the text file.
//   -- Assuming that the input file is formatted correctly (2 ints on one line
//      for an edge, etc.).
//   -- We begin use of the graph array at element 1, ignoring element 0
//      so as to reduce confusion as we build graphs that use one-based
//      indexing.
//   -- Break reading from the text file when 0 is passed in.
//---------------------------------------------------------------------------

const int MAXNODES_L = 101; // global constant max nodes

class GraphL {
public:
    GraphL(); // GraphL constructor
    ~GraphL(); // GraphL destructor
    void buildGraph(istream&); // builds the graph from input file
    void displayGraph() const; // displays all of the edges of the graph
    void depthFirstSearch(); // performs depth first search on the graph

private:
    int size;
    struct EdgeNode; // forward reference for the compiler
    struct GraphNode {
        EdgeNode* edgeHead; // head of the list of edges
        NodeData* data; // holds the node data
        bool visited; // holds whether node has been visited in dfs
    };
    struct EdgeNode {
        int adjGraphNode; // subscript of the adjacent graph node
        EdgeNode* nextEdge; // holds the next EdgeNode connected to this node
    };
    GraphNode graph[MAXNODES_L]; // GraphNode array of 101 elements
    void dfs(EdgeNode*); // helper method for depthFirstSearch
    void displayUtil(EdgeNode*, int) const; // helper method for displayUtil
    void makeEmpty(); // deletes the graph

};

#endif //GRAPHL_H
