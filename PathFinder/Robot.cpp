//
// Created by Anthony Joo on 2019-01-24.
//

#include "Robot.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

Robot::Robot(const int maxStepsDir, int xr, int yr, const int xt, const int yt)
{
    this->maxStepsDir = maxStepsDir;
    this->xr = xr;
    this->yr = yr;
    this->xt = xt;
    this->yt = yt;
    paths;
    seen;
}

Robot::Robot()
{
    this->maxStepsDir = 0;
    this->xr = 0;
    this->yr = 0;
    this->xt = 0;
    this->yt = 0;
    paths;
    seen;
}

void Robot::setMaxConsec(const int maxStepsDir)
{
    this->maxStepsDir = maxStepsDir;
}

void Robot::setXStart(const int xr)
{
    this->xr = xr;
}

void Robot::setYStart(const int yr)
{
    this->yr = yr;
}

void Robot::setXEnd(const int xt)
{
    this->xt = xt;
}

void Robot::setYEnd(const int yt)
{
    this->yt = yt;
}

bool Robot::isMaxSteps(const int maxStepsDir, string answer) const
{
    if(answer.length() <= maxStepsDir || maxStepsDir == 0)
    {
        return false;
    }
    char ch = answer[answer.length() - 1];
    for(int i = answer.length() - 2; i >= answer.length() - maxStepsDir - 1; i--)
    {
        if(ch != answer[i])
        {
            return false;
        }
    }
    return true;
}

void Robot::findPaths(const int x, const int y, string answer, const Board &b, vector<int> saw)
{
    if(b.InBounds(x, y) && !b.Blocked(x, y) && !isMaxSteps(maxStepsDir, answer) && !visited(x, y, saw))
    {
        if (x == xt && y == yt)
        {
            paths.push_back(answer);
        } else
        {
            saw.push_back(x);
            saw.push_back(y);
            findPaths(x, y + 1, answer + "N", b, saw);
            findPaths(x + 1, y, answer + "E", b, saw);
            findPaths(x, y - 1, answer + "S", b, saw);
            findPaths(x - 1, y, answer + "W", b, saw);
        }
    }
}

void Robot::narrowPaths()
{
    vector<string> narrow;
    if(paths.size() != 0)
    {
        int least = paths.at(0).size();
        for(int i = 1; i < paths.size(); i++)
        {
            int next = paths.at(i).size();
            if(next < least)
            {
                least = next;
            }
        }
        for(int i = 0; i < paths.size(); i++)
        {
            string one = paths.at(i);
            if(one.size() == least)
            {
                cout << one << endl;
                narrow.push_back(one);
            }
        }
    }
    cout << "Number of paths: " << narrow.size() << endl;
}

bool Robot::visited(const int x, const int y, const vector<int> saw) const
{
    if(!saw.empty())
    {
        for(int i = 0; i < saw.size(); i+=2)
        {
            if(x == saw.at(i) && y == saw.at(i + 1))
            {
                return true;
            }
        }
    }
    return false;
}

void Robot::FindPath(const Board &b)
{
    findPaths(xr, yr, "", b, seen);
    narrowPaths();
}