//
// Created by Anthony Joo on 2019-01-24.
//

#include "Board.h"
#include <iostream>
#include <vector>

Board::Board(const int xbounds, const int ybounds, const vector<int> &obs)
{
    this->xbounds = xbounds;
    this->ybounds = ybounds;
    this->obs = obs;
}

Board::Board()
{
    this->xbounds = 0;
    this->ybounds = 0;
    obs;
}

void Board::setX(const int xbounds)
{
    this->xbounds = xbounds;
}

void Board::setY(const int ybounds)
{
    this->ybounds = ybounds;
}

void Board::setBlocks(const vector<int> &obs)
{
    this->obs = obs;
}

bool Board::InBounds(const int x, const int y) const
{
    return x <= xbounds - 1 && y <= ybounds - 1 && x >= 0 && y >= 0;
}

bool Board::Blocked(const int x, const int y) const
{
    for(int i = 0; i < obs.size(); i+=2)
    {
        if(x == obs.at(i) && y == obs.at(i + 1))
        {
            return true;
        }
    }
    return false;
}