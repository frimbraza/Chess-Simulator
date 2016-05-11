#include "coordinate.h"

Coordinate::Coordinate(int x, int y)
{
        xCoord = x;
        yCoord = y;
}

Coordinate::~Coordinate()
{

}

void Coordinate::set(int x, int y)
{
        xCoord = x;
        yCoord = y;
}

int Coordinate::getX()
{
    return xCoord;
}

int Coordinate::getY()
{
    return yCoord;
}

bool operator==(Coordinate c_1, Coordinate c_2)
{
    return (c_1.xCoord == c_2.xCoord && c_1.yCoord == c_2.yCoord);
}




