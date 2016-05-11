#include "tile.h"
#include "piece.h"

Tile::Tile()
{
    occupant = NULL;
}

Tile::Tile(Piece* pieceName)
{
    setOccupant(pieceName);
}


Tile::~Tile()
{
}

void Tile::setOccupant(Piece *pieceName)
{
    occupant = pieceName;
}

Piece* Tile::getOccupant()
{
    return occupant;
}

bool Tile::empty()
{
    return !occupant;
}

void Tile::print()
{
   //Print space if occupant is NULL:
    if(occupant != NULL)
        occupant->print();
    else
        cout << " ";
}
