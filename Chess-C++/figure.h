#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#include <vector>
#include "field.h"
class Field;
class Figure
{
    Field* field;
    Color c;
    bool selected;
public:
    Figure(Field* field, Color c);
    Color getColor() {return c;}
    Field* getField() {return field;}
    void setField(Field* f) {field=f;}
    bool getSelected() {return selected;}
    void setSelected(bool s) {selected=s;}
    virtual FieldList whereToStep()=0;
    virtual FieldList whereToHit()=0;
    virtual void draw() =0;
    virtual ~Figure() {}
protected:
    void generateSteps(FieldList& fieldList, int dx, int dy, int max);

};
class FigureSet :public std::vector<Figure*>
{
    PlayerType playeType;
    Figure* king;

public:
    FigureSet(PlayerType p=AUTO) :playeType(p) {}
    PlayerType getPlayerType(){return playeType;}
    Figure* getKing() {return king;}
    void setKing(Figure* k) {king=k;}
    void winGame();


};

class Pawn :public Figure
{
public:

	Pawn(Field* field, Color c) :Figure(field, c) {}
    virtual void draw();
    virtual FieldList whereToStep();
    virtual FieldList whereToHit();
};


class Knight :public Figure
{
public:

	Knight(Field* field, Color c) :Figure(field, c) {}
    virtual void draw();
    virtual FieldList whereToStep();
    virtual FieldList whereToHit();
};
class Bishop :public Figure
{
public:

	Bishop(Field* field, Color c) :Figure(field, c) {}
    virtual void draw();
    virtual FieldList whereToStep();
    virtual FieldList whereToHit();
};
class Rook :public Figure
{
public:

	Rook(Field* field, Color c) :Figure(field, c) {}
    virtual void draw();
    virtual FieldList whereToStep();
    virtual FieldList whereToHit();
};
class Queen :public Figure
{
public:

	Queen(Field* field, Color c) :Figure(field, c) {}
    virtual void draw();
    virtual FieldList whereToStep();
    virtual FieldList whereToHit();
};
class King :public Figure
{
public:

	King(Field* field, Color c) :Figure(field, c) {}
    virtual void draw();
    virtual FieldList whereToStep();
    virtual FieldList whereToHit();
};
#endif // FIGURE_H_INCLUDED
