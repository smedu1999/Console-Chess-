#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "memtrace.h"
#include "test.h"

ChessTest::~ChessTest()
{

}

bool ChessTest::testRook()
{
    DemChess chess(true);
    Figure* figure;
    Board& board=chess.board;
    chess.whiteFigures.push_back(new Rook(board.getField(4,4),WHITE));
    figure=chess.whiteFigures[0];
    FieldList fList;
    Position from;
    Position to;
    FieldList stepList=figure->whereToStep();
    bool inCheck=false;
    chess.getAutMove(chess.whiteFigures,from,to);
    chess.step(chess.whiteFigures,figure->getField()->getPos(),to,inCheck);
    fList.push_back(board.getField(0,4));
    fList.push_back(board.getField(1,4));
    fList.push_back(board.getField(2,4));
    fList.push_back(board.getField(3,4));
    fList.push_back(board.getField(5,4));
    fList.push_back(board.getField(6,4));
    fList.push_back(board.getField(7,4));
    fList.push_back(board.getField(4,0));
    fList.push_back(board.getField(4,1));
    fList.push_back(board.getField(4,2));
    fList.push_back(board.getField(4,3));
    fList.push_back(board.getField(4,5));
    fList.push_back(board.getField(4,6));
    fList.push_back(board.getField(4,7));
    if(fList.size()!=stepList.size())

        return false;
   else
    {
        bool x=false;
        for(unsigned int i=0; i<fList.size();i++)
        {
            for(unsigned int j=0; j<stepList.size();j++)
            {
                if(stepList[j]==fList[i])
                    x=true;
            }
            if(x==false)
                return false;
            x=false;
        }
        return true;
    }
    return true;

}
bool ChessTest::testQueen()
{

    DemChess chess(true);
    Figure* figure;
    Board& board=chess.board;
    chess.whiteFigures.push_back(new Queen(board.getField(4,4),WHITE));
    figure=chess.whiteFigures[0];
    FieldList fList;
    Position from;
    Position to;
    FieldList stepList=figure->whereToStep();
    bool inCheck=false;
    chess.getAutMove(chess.whiteFigures,from,to);
    chess.step(chess.whiteFigures,figure->getField()->getPos(),to,inCheck);
    fList.push_back(board.getField(0,4));
    fList.push_back(board.getField(1,4));
    fList.push_back(board.getField(2,4));
    fList.push_back(board.getField(3,4));
    fList.push_back(board.getField(5,4));
    fList.push_back(board.getField(6,4));
    fList.push_back(board.getField(7,4));
    fList.push_back(board.getField(4,0));
    fList.push_back(board.getField(4,1));
    fList.push_back(board.getField(4,2));
    fList.push_back(board.getField(4,3));
    fList.push_back(board.getField(4,5));
    fList.push_back(board.getField(4,6));
    fList.push_back(board.getField(4,7));

    fList.push_back(board.getField(5,5));
    fList.push_back(board.getField(6,6));
    fList.push_back(board.getField(7,7));
    fList.push_back(board.getField(3,3));
    fList.push_back(board.getField(2,2));
    fList.push_back(board.getField(1,1));
    fList.push_back(board.getField(0,0));
    fList.push_back(board.getField(3,5));
    fList.push_back(board.getField(2,6));
    fList.push_back(board.getField(1,7));
    fList.push_back(board.getField(5,3));
    fList.push_back(board.getField(6,2));
    fList.push_back(board.getField(7,1));
    if(fList.size()!=stepList.size())
        return false;
    else
    {
        bool x=false;
        for(unsigned int i=0; i<fList.size();i++)
        {
            for(unsigned int j=0; j<stepList.size();j++)
            {
                if(stepList[j]==fList[i])
                    x=true;
            }
            if(x==false)
                return false;
            x=false;
        }
        return true;
    }
    return true;
}

bool ChessTest::testKnight()
{

    DemChess chess(true);
    Figure* figure;
    Board& board=chess.board;
    chess.whiteFigures.push_back(new Knight(board.getField(4,4),WHITE));
    figure=chess.whiteFigures[0];
    FieldList fList;
    Position from;
    Position to;
    FieldList stepList=figure->whereToStep();
    bool inCheck=false;
    chess.getAutMove(chess.whiteFigures,from,to);
    chess.step(chess.whiteFigures,figure->getField()->getPos(),to,inCheck);
    fList.push_back(board.getField(2,3));
    fList.push_back(board.getField(2,5));
    fList.push_back(board.getField(6,3));
    fList.push_back(board.getField(6,5));
    fList.push_back(board.getField(3,2));
    fList.push_back(board.getField(3,6));
    fList.push_back(board.getField(5,2));
    fList.push_back(board.getField(5,6));

    if(fList.size()!=stepList.size())
        return false;
    else
    {
        bool x=false;
        for(unsigned int i=0; i<fList.size();i++)
        {
            for(unsigned int j=0; j<stepList.size();j++)
            {

                if(stepList[j]==fList[i])
                {
                    x=true;

                }
            }
            if(x==false)
                return false;
            x=false;
        }
        return true;
    }
    return true;

}

bool ChessTest::testBishop()
{

    DemChess chess(true);
    Figure* figure;
    Board& board=chess.board;
    chess.whiteFigures.push_back(new Bishop(board.getField(4,4),WHITE));
    figure=chess.whiteFigures[0];
    FieldList fList;
    Position from;
    Position to;
    FieldList stepList=figure->whereToStep();
    bool inCheck=false;
    chess.getAutMove(chess.whiteFigures,from,to);
    chess.step(chess.whiteFigures,figure->getField()->getPos(),to,inCheck);
    fList.push_back(board.getField(5,5));
    fList.push_back(board.getField(6,6));
    fList.push_back(board.getField(7,7));
    fList.push_back(board.getField(3,3));
    fList.push_back(board.getField(2,2));
    fList.push_back(board.getField(1,1));
    fList.push_back(board.getField(0,0));
    fList.push_back(board.getField(3,5));
    fList.push_back(board.getField(2,6));
    fList.push_back(board.getField(1,7));
    fList.push_back(board.getField(5,3));
    fList.push_back(board.getField(6,2));
    fList.push_back(board.getField(7,1));
    if(fList.size()!=stepList.size())
        return false;
    else
    {
        bool x=false;
        for(unsigned int i=0; i<fList.size();i++)
        {

            for(unsigned int j=0; j<stepList.size();j++)
            {
                if(stepList[j]==fList[i])
                    x=true;
            }
            if(x==false)
                return false;
            x=false;
        }
        return true;
    }
    return true;
}

bool ChessTest::testKing()
{
    DemChess chess(true);
    Figure* figure;
    Board& board=chess.board;
    chess.whiteFigures.push_back(new King(board.getField(4,4),WHITE));
    figure=chess.whiteFigures[0];
    FieldList fList;
    Position from;
    Position to;
    FieldList stepList=figure->whereToStep();
    bool inCheck=false;
    chess.getAutMove(chess.whiteFigures,from,to);
    chess.step(chess.whiteFigures,figure->getField()->getPos(),to,inCheck);
    fList.push_back(board.getField(3,4));
    fList.push_back(board.getField(5,4));
    fList.push_back(board.getField(5,5));
    fList.push_back(board.getField(3,3));
    fList.push_back(board.getField(4,3));
    fList.push_back(board.getField(4,5));
    fList.push_back(board.getField(3,5));
    fList.push_back(board.getField(5,3));

    if(fList.size()!=stepList.size())
        return false;
    else
    {
        bool x=false;
        for(unsigned int i=0; i<fList.size();i++)
        {
            for(unsigned int j=0; j<stepList.size();j++)
            {
                //std::cout<<stepList[j]->getPos().x<<stepList[j]->getPos().y<<std::endl;
                //std::cout<<fList[i]->getPos().x<<fList[i]->getPos().y<<std::endl;
            for(unsigned int j=0; j<stepList.size();j++)
                if(stepList[j]==fList[i])
                    x=true;
            }
            if(x==false)
                return false;
            x=false;
        }
        return true;
    }
    return true;

}

bool ChessTest::testPawn()
{

    DemChess chess(true);
    Figure* figure;
    Board& board=chess.board;
    chess.whiteFigures.push_back(new Pawn(board.getField(4,4),WHITE));
    figure=chess.whiteFigures[0];
    FieldList fList;
    Position from;
    Position to;
    FieldList stepList=figure->whereToStep();
    bool inCheck=false;
    chess.getAutMove(chess.whiteFigures,from,to);
    chess.step(chess.whiteFigures,figure->getField()->getPos(),to,inCheck);
    if(figure->getColor()==WHITE)
        fList.push_back(board.getField(5,4));
    else
        fList.push_back(board.getField(3,4));
    if(fList.size()!=stepList.size())
        return false;
    else
    {
        bool x=false;
        for(unsigned int i=0; i<fList.size();i++)
        {
            for(unsigned int j=0; j<stepList.size();j++)
            {
                if(stepList[j]==fList[i])
                    x=true;
            }
            if(x==false)
                return false;
            x=false;
        }
        return true;
    }
    return true;

}

