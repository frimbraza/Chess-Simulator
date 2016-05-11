#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
    public:
         Coordinate(int x = 0, int y = 0);
        ~Coordinate();

         void set(int x, int y);
         int getX();
         int getY();
         friend bool operator==(Coordinate c_1, Coordinate c_2);

    private:
         int xCoord;
         int yCoord;
};

#endif // COORDINATE_H
