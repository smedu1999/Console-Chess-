#include "board.h"
Board::Board()
{
    cursoredField=getField(0,0);
    for(int i=0; i<BOARDSIZE;i++)
    {
        for(int j=0; j<BOARDSIZE;j++)
        {
            Color c=(i+j)% 2==0 ? WHITE : BLACK;
            board[i][j].init(this,Position(i,j),c);
        }
    }
};

Field* Board::getField(int x, int y)
{
    if(!checkPos(Position(x,y)))
        return NULL;

    return &board[x][y];
}

void Board::draw()
{
    for(int i=0; i<BOARDSIZE;i++)
    {
        for(int j=0; j<BOARDSIZE;j++)
        {
            board[i][j].draw();
        }
    }
}
