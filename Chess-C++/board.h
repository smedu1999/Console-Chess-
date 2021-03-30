#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "figure.h"
class Figure;
class Board
{
    Field board[BOARDSIZE][BOARDSIZE];
    Field* cursoredField;
public:
    Board();
    Field* getCursor() {return cursoredField;}
    void setCursor(Field* f) {cursoredField=f;}
    Field* getField(int x, int y);
    bool checkPos(Position pos) {return (pos.x>=0&&pos.x<BOARDSIZE&&pos.y<BOARDSIZE&&pos.y>=0);}

    void draw();

};


#endif // BOARD_H_INCLUDED
