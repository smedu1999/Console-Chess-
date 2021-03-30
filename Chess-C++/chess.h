#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED
#include "board.h"

class FigureSet;
class DemChess
{
friend class ChessTest;
    Board board;
    FigureSet whiteFigures;
    FigureSet blackFigures;
    bool winGame;
public:
    DemChess(PlayerType w=MANUAL, PlayerType b=AUTO, bool win=false);
    DemChess(bool test){}
    void playGame();
    FigureSet& getWhiteFigures() {return whiteFigures;}
    FigureSet& getBlackFigures() {return blackFigures;}
    bool getManMove(FigureSet& f, Position& from, Position& to);
    bool getAutMove(FigureSet& f, Position& from, Position& to);
    bool step(FigureSet& fset, Position from, Position to,bool& inCheck);
    bool oneTurn(FigureSet& fset);
    bool checkAttack(Figure* figure);
    void initGame();
    void saveGame();
    void draw();
    void drawMenu(const char* c);
    ~DemChess();

};




#endif // CHESS_H_INCLUDED
