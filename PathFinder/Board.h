//
// Created by Anthony Joo on 2019-01-24.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
    // Constructors
    Board(const int xbounds, const int ybounds, const vector<int> &obs);
    Board();

    // Setter methods
    void setX(const int xbounds); // Allows the user to set the x bound of the board.
    void setY(const int ybounds); // Allows the user to set the y bound of the board.
    void setBlocks(const vector<int> &obs); // Defines the positions on the board that are block

    // Check methods
    bool InBounds(const int x, const int y) const; // Checks if the given x and y values are within the bounds of the
                                                   // board.
    bool Blocked(const int x, const int y) const; // Checks if the position given byt he x and y values is blocked.

private:
    int xbounds; // X limit of board.
    int ybounds; // Y limit of map.
    vector<int> obs; // Vector of obstructed positions.
};

#endif //CSS342LAB2_BOARD_H