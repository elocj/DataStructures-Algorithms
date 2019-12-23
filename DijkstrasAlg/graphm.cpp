// file graphM.cpp
// Member function definitions for class GraphM

#include "graphm.h"

// ---------------------------------------------------------------------------
// Constructor
// Constructs a GraphM class that sets size to 0, the values in the cost matrix
// to infinity, and TableType distances to infinity, visited to false, and path
// to zero.

GraphM::GraphM() {
    size = 0;
    for(auto& row : C) {
        for(auto& col: row) {
            col = INFINITY;
        }
    }
    for(auto& row : T) {
        for(auto& col : row) {
            col.dist = INFINITY;
            col.visited = false;
            col.path = 0;
        }
    }
}

// ---------------------------------------------------------------------------
// buildGraph
// pre: takes in an input file that holds graph data
// post: builds a graph with nodes and edges from the input file and assigns
//       values to the TableType and cost matrix accordingly

void GraphM::buildGraph(istream& infile) {
    int fromNode, toNode, value;
    infile >> size;
    if(infile.eof()) return;
    string s;
    getline(infile, s);
    for(int i = 1; i <= size; i++) {
        data[i].setData(infile);
    }
    for(;;) {
        infile >> fromNode >> toNode >> value;
        if(fromNode == 0 && toNode == 0 && value == 0) return;
        if(fromNode > 0 && toNode > 0 && fromNode <= 100 && toNode <= 100) {
            C[fromNode][toNode] = value;
        }
    }
};

// ---------------------------------------------------------------------------
// insertEdge
// pre: takes in a fromNode, toNode, and value or the origin node index, the
//      destination node index, and the cost value to place along the edge
//      of these two nodes. If an already existing edge is passed in its cost
//      value will be replaced by the newly passed in value.
// post: if these two nodes exist an edge is built between them with the
//       passed in cost

void GraphM::insertEdge(int fromNode, int toNode, int value) {
    if(fromNode > size || toNode > size || fromNode <= 0 || toNode <= 0
    || value <= 0) {
        return;
    }
    C[fromNode][toNode] = value;
    findShortestPath();
}

// ---------------------------------------------------------------------------
// removeEdge
// pre: takes in a fromNode and a toNode, or the origin node index and the
//      destination node index
// post: if an edge between these two nodes exist it is deleted

void GraphM::removeEdge(int fromNode, int toNode) {
    if(fromNode > 100 || toNode > 100 || fromNode <= 0 || toNode <= 0
    || C[fromNode][toNode] == INFINITY) {
        return;
    }
    C[fromNode][toNode] = INFINITY;
    findShortestPath();
}

// ---------------------------------------------------------------------------
// findShortestPath
// finds the shortest path between every pair of nodes possible using Dijkstra's
// algorithm

void GraphM::findShortestPath() {
    makeEmpty();
    for(int source = 1; source <= size; source++) {
        T[source][source].dist = 0;
        T[source][source].path = source;
        for(int count = 1; count < size; count++) {
            int minIndex = 0;
            for(int i = 1; i <= size; i++) { //
                if(T[source][minIndex].dist >= T[source][i].dist
                && !T[source][i].visited) {
                    minIndex = i;
                }
            }
            T[source][minIndex].visited = true;
            for(int w = 1; w <= size; w++) {
                if(!T[source][w].visited && C[minIndex][w] != INFINITY
                && T[source][minIndex].dist != INFINITY
                && T[source][minIndex].dist + C[minIndex][w]
                < T[source][w].dist) {
                    T[source][w].dist = T[source][minIndex].dist
                            + C[minIndex][w];
                    T[source][w].path = minIndex;
                }
                //iterate through each w for given minIndex
            }
        }
    }
}

// ---------------------------------------------------------------------------
// makeEmpty
// will make the T matrix empty so that findShortestPath can run again

void GraphM::makeEmpty() {
    for(auto& row : T) {
        for(auto& col : row) {
            col.dist = INFINITY;
            col.visited = false;
            col.path = 0;
        }
    }
}

// ---------------------------------------------------------------------------
// displayAll
// displays all of the possible node pair combinations and if an edge exists
// between them it lists the shortest path between the two

void GraphM::displayAll() const {
    cout << "Description               From node     To Node     Dijkstra's"
            "     Path" << endl;
    for(int i = 1; i <= size; i++) {
        cout << data[i] << endl;
        for(int j = 1; j <= size; j++) {
            if(j != i) {
                cout << "                              " << i
                << "            " << j << "           ";
                if(T[i][j].path == 0) {
                    cout << "----";
                } else {
                    cout << "  " << T[i][j].dist << "        ";
                    int index = j;
                    displayHelper(index, i);
                }
                cout << endl;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// displayHelper
// pre: takes in an index value that acts as a origin node as well as i value
//      which acts as a destination node
// post: this is a helper method for displayAll and displays the shortest
//       path between two nodes following TableType path values

void GraphM::displayHelper(int index, int i) const {
    if(T[i][index].path == 0) {
        return;
    }
    if(index == i) {
        cout << i;
        return;
    }
    displayHelper(T[i][index].path, i);
    cout << " " << index;
}

// ---------------------------------------------------------------------------
// display
// pre: takes in a start and end for an origin node and a destination node
// post: displays the shortest path between a specific pair of nodes

void GraphM::display(int start, int end) const {
    cout << start << "     " << end << "     ";
    if(T[start][end].path == 0) {
        cout << "----" << endl;
    } else {
        cout << T[start][end].dist << "          ";
    }
    displayHelper(end, start);
    cout << endl;
    locationHelper(end, start);
}

// ---------------------------------------------------------------------------
// locationHelper
// pre: takes in an index value that acts as a origin node as well as i value
//      which acts as a destination node
// post: this is a helper method for display and displays the locations visited
//       on the shortest path from the origin to destination

void GraphM::locationHelper(int index, int i) const {
    if (T[i][index].path == 0) {
        return;
    }
    if (index == i) {
        cout << data[i] << endl;
        return;
    }
    locationHelper(T[i][index].path, i);
    cout << data[index] << endl;
}
