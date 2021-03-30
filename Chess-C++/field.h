#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include "common.h"
#include<stdlib.h>
#include <vector>
class FigureSet;
class Figure;
class Board;
class Field
{
    Board* board;
    Color color;
    Position pos;
    Figure* figure;
    bool hasCursor;
public:
    Field() :color(BLACK), figure(NULL), hasCursor(false){}
    Position getPos() {return pos;}
    Color getColor() {return color;}
    Figure* getFigure() {return figure;}
    Board* getBoard() {return board;}
    bool getHasCursor() {return hasCursor;}
    void init(Board* board, Position pos, Color col) {this->pos=pos; color=col; this->board=board;}
    void setFigure(Figure* f){figure=f;}
    void setCursor(bool b) {hasCursor=b;}
    void draw();
};

typedef std::vector<Field*> FieldList;

#endif // FIELD_H_INCLUDED
