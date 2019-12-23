//
// Created by Anthony Joo on 2019-01-24.
// implement board in robot

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "Board.h"
#include <vector>

using namespace std;

class Robot
{
public:
    // Constructors
    Robot(const int maxStepsDir, int xr, int yr, const int xt, const int yt);
    Robot();

    // Setter methods
    void setMaxConsec(const int maxStepsDir); // Sets the maximum allowed number of consecutive steps.
    void setXStart(const int xr); // Sets the starting x value of the robot.
    void setYStart(const int yr); // Sets the starting y value of the robot.
    void setXEnd(const int xt); // Sets the ending x value of the robot.
    void setYEnd(const int yt); // Sets the ending y value of the robot.

    // Recursive method
    void FindPath(const Board &b); // Finds the optimal path from the robot to the treasure point.

private:
    // Check methods
    bool isMaxSteps(const int maxStepsDir, string answer) const; // Checks if the robot has made the same consecutively
                                                                 // for more than the allowed amount.
    void findPaths(const int x, const int y, string answer, const Board &b, vector<int> saw); // Helper method to
                                                                                              // perform the recursion
                                                                                              // needed to find the
                                                                                              // optimal path to the
                                                                                              // treasure.
    void narrowPaths(); // Narrows down all of the paths to find the most optimal paths.
    bool visited(const int x, const int y, const vector<int> saw) const; // Checks if the given position on the board
                                                                         // has been visited.

    // when method is called it doesnt change state of this robot
    // if method doesnt change stat of this object then const
    int maxStepsDir; // Defines the maximum allowed of consecutive steps in the same direction.
    int xr; // Defines the starting x value of the robot.
    int yr; // Defines the starting y value of the robot.
    int xt; // Defines the ending x value of the robot.
    int yt; // Defines the ending y value of the robot.
    vector<string> paths; // Vector of possible paths the robot could take to the treasure.
    vector<int> seen; // Vector of previously visited paths of the robot.
};

#endif //CSS342LAB2_ROBOT_H