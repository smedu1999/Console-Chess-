#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "chess.h"

class FigureSet;

class ChessTest
{
public:
    ChessTest();
    static bool testPawn();
    static bool testRook();
    static bool testKnight();
    static bool testKing();
    static bool testQueen();
    static bool testBishop();
    ~ChessTest();
};

#endif // TEST_H_INCLUDED
