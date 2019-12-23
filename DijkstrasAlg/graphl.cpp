// file graphl.cpp
// Member function definitions for class GraphL

#include "graphl.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs a GraphL class that sets size to 0, and every graph element's
// visited to 0, data to nullptr, and edgeHead to nullptr.

GraphL::GraphL() {
    size = 0;
    for(auto& element : graph) {
        element.edgeHead = nullptr;
        element.visited = false;
        element.data = nullptr;
    }
}

// ---------------------------------------------------------------------------
// Destructor
// Deletes the graph using makeEmpty

GraphL::~GraphL() {
    makeEmpty();
}

// ---------------------------------------------------------------------------
// makeEmpty
// Deletes the graph

void GraphL::makeEmpty() {
    for(int i = 1; i <= size; i++) {
        delete graph[i].data;
        graph[i].data = nullptr;
        if(graph[i].edgeHead != nullptr) {
            EdgeNode* temp = graph[i].edgeHead;
            while(temp != nullptr) {
                graph[i].edgeHead = graph[i].edgeHead->nextEdge;
                delete temp;
                temp = graph[i].edgeHead;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// buildGraph
// Pre: takes in an input file that holds graph data
// Post: builds a graph with nodes and edges from the input file

void GraphL::buildGraph(istream& infile) {
    int fromNode, toNode;              // from and to node ends of edge

    makeEmpty();                       // clear the graph of memory

    infile >> size;                    // read the number of nodes
    if (infile.eof()) return;          // stop if no more data

    string s;                          // used to read through to end of line
    getline(infile, s);

    // read graph node information
    for (int i=1; i <= size; i++) {
        graph[i].data = new NodeData();
        graph[i].data->setData(infile);
        graph[i].edgeHead = new EdgeNode();
        graph[i].edgeHead->adjGraphNode = i;
    }

    // read the edge data and add to the adjacency list
    for (;;) {
        infile >> fromNode >> toNode;
        if (fromNode ==0 && toNode ==0) return;     // end of edge data
        EdgeNode* temp = graph[fromNode].edgeHead;
        while(temp->nextEdge != nullptr) {
            temp = temp->nextEdge;
        }
        temp->nextEdge = new EdgeNode();
        temp->nextEdge->adjGraphNode = toNode;
        // insert the edge into the adjacency list for fromNode
    }
}

// ---------------------------------------------------------------------------
// buildGraph
// carries out and prints the nodes traversed with depth first search.

void GraphL::depthFirstSearch() {
    cout << endl;
    cout << "Depth-first ordering: ";
    for(int i = 1; i < size; i++) {
        if(!graph[i].visited) {
            cout << i << " ";
            EdgeNode* temp = graph[i].edgeHead;
            dfs(temp->nextEdge);
        }
    }
    cout << endl;
    cout << endl;
}

// ---------------------------------------------------------------------------
// dfs
// pre: takes in a pointer to an EdgeNode
// post: this is a helper method for depth first search and the pointer to the
//       edgeNode is used to perform depth first search and print the traversals

void GraphL::dfs(EdgeNode* temp) {
    if(temp == nullptr) {
        return;
    }
    dfs(temp->nextEdge);
    if(graph[temp->adjGraphNode].visited) {
        return;
    }
    graph[temp->adjGraphNode].visited = true;
    cout << temp->adjGraphNode << " ";
    temp = graph[temp->adjGraphNode].edgeHead;
    dfs(temp);
}

// ---------------------------------------------------------------------------
// displayGraph
// displays the edges in the graph as well as the location associated with the
// origin nodes

void GraphL::displayGraph() const {
    cout << "Graph:" << endl;
    for(int i = 1; i <= size; i++) {
        EdgeNode* temp = graph[i].edgeHead;
        cout << "Node " << i << "       " << *graph[i].data << endl;
        displayUtil(temp->nextEdge, i);
    }
}

// ---------------------------------------------------------------------------
// displayUtil
// pre: takes in a pointer to an EdgeNode and the index of the origin node
// post: this is a helper method for displayGraph and the pointer to the
//       edgeNode is used to print the edges in depth first search order

void GraphL::displayUtil(EdgeNode* temp, int i) const {
    if(temp == nullptr) {
        return;
    }
    displayUtil(temp->nextEdge, i);
    cout << "  edge " << i << " " << temp->adjGraphNode << endl;
}
