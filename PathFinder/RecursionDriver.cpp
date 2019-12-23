//
// Created by Anthony Joo on 2019-01-23.
//

#include <iostream>
#include "Board.h"
#include "Robot.h"
#include <string>
#include <vector>

int main()
{
    // Test case 1: Tests the response of the program when there are no blocked locations on the board.
    Board B1(4,6,{});
    Robot R1(0,1,2,3,5);
    R1.FindPath(B1);

    // Test case 2: Tests another set of initial parameter values.
    Board B2(5,5,{1,2,2,4,3,3,3,4,4,2,4,4});
    Robot R2(3,1,4,4,1);
    R2.FindPath(B2);

    // Test case 3: Tests another set of initial parameter values.
    Board B3(7,7,{1,1,3,1,4,1,1,2,1,6,2,4,3,3,3,5,4,3,4,5,6,2,6,3,6,4,6,5,6,6});
    Robot R3(3,6,1,2,6);
    R3.FindPath(B3);

    // Test case 4: Tests another set of initial parameter values.
    Board B4(5, 5, {1, 2, 1, 3});
    Robot R4(2, 1, 4, 4, 1);
    R4.FindPath(B4);

    // Test case 5: Tests the response of the program when the board boundaries are defined to be zero. Correct output
    //              should be 0 paths.
    Board B5(0, 0, {1, 2, 1, 3});
    Robot R5(2, 1, 4, 4, 1);
    R5.FindPath(B5);

    // Test case 6: Tests whether the user can declare a board and robot object without parameters. Also tests whether
    //              the user can manually input values for the parameters later. Test uses the same initial values as
    //              Test Case 1 and so should pass if the output is identical to Test Case 1.
    Board B6;
    B6.setX(4);
    B6.setY(6);
    B6.setBlocks({});
    Robot R6;
    R6.setMaxConsec(0);
    R6.setXStart(1);
    R6.setYStart(2);
    R6.setXEnd(3);
    R6.setYEnd(5);
    R6.FindPath(B6);

    // Test case 7: Tests the programs response when the start point is the same as the end point. This issue comes down
    //              to an issue of definition of what counts as a path to the final point. Because the start is the
    //              finish one could say there is only one path and that is to simply stay where it is. I have decided
    //              to define the output of this specific case as such and so the correct output should be 1 path
    //              detected.
    Board B7(4,6,{});
    Robot R7(0,1,2,1,2);
    R7.FindPath(B7);

    // Test case 8: Tests the programs response when the treasure is at a point out of the first quadrant where it is
    //              not allowed. In this case the output should be zero because there is no way for the robot to
    //              traverse out of the allowed bounds.
    Board B8(4,6,{});
    Robot R8(0,1,2,-2,-4);
    R8.FindPath(B8);

    return 0;
}