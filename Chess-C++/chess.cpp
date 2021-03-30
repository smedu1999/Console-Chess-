#include "chess.h"
#include "figure.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;

void DemChess::initGame()
{
    whiteFigures.push_back(new Rook     (board.getField(0,0),WHITE));
    whiteFigures.push_back(new Knight   (board.getField(0,1),WHITE));
    whiteFigures.push_back(new Bishop   (board.getField(0,2),WHITE));
    whiteFigures.push_back(new King     (board.getField(0,3),WHITE));
    whiteFigures.push_back(new Queen    (board.getField(0,4),WHITE));
    whiteFigures.push_back(new Bishop   (board.getField(0,5),WHITE));
    whiteFigures.push_back(new Knight   (board.getField(0,6),WHITE));
    whiteFigures.push_back(new Rook     (board.getField(0,7),WHITE));

    blackFigures.push_back(new Rook     (board.getField(7,0),BLACK));
    blackFigures.push_back(new Knight   (board.getField(7,1),BLACK));
    blackFigures.push_back(new Bishop   (board.getField(7,2),BLACK));
    blackFigures.push_back(new King     (board.getField(7,3),BLACK));
    blackFigures.push_back(new Queen    (board.getField(7,4),BLACK));
    blackFigures.push_back(new Bishop   (board.getField(7,5),BLACK));
    blackFigures.push_back(new Knight   (board.getField(7,6),BLACK));
    blackFigures.push_back(new Rook     (board.getField(7,7),BLACK));

    for (int i=0;i<8;i++)
    {
        whiteFigures.push_back(new Pawn (board.getField(1,i),WHITE));
        blackFigures.push_back(new Pawn (board.getField(6,i),BLACK));
    }

}
DemChess::DemChess(PlayerType w, PlayerType b, bool win) :whiteFigures(w),blackFigures(b), winGame(win)
{
    initGame();
};
bool DemChess::oneTurn(FigureSet& currentPlayer)
{
    bool inCheck=false;
    system("cls");
    draw();
    for(int i=0;i<100;i++)
    {
        Position from;
        Position to;
        bool canMove=false;
        switch(currentPlayer.getPlayerType())
        {
        case MANUAL:
            {
                canMove=getManMove(currentPlayer,from, to);
                break;
            }
        case AUTO:
            {
                //getch();
                canMove=getAutMove(currentPlayer, from, to);
                break;
            }
        }
        if(canMove)
        {
            if(step(currentPlayer,from, to, inCheck))
            {
                return true;
            }


        }
        else
        {
             if(currentPlayer.getPlayerType()==MANUAL)
                break;

        }
    }
    if(inCheck)
    {
        winGame=true;
    }
    return false;

}

void DemChess::playGame()
{

    whiteFigures.setKing(whiteFigures[3]);
    blackFigures.setKing(blackFigures[3]);
    srand (time (NULL));
    FigureSet* currentPlayer=NULL;
    for( currentPlayer=&whiteFigures
       ; winGame!=true
       ; currentPlayer= currentPlayer==&whiteFigures ? &blackFigures : &whiteFigures
       )
    {
        if(!oneTurn(*currentPlayer))
            break;
    }
    currentPlayer->winGame();
    system("cls");

};



bool DemChess::step(FigureSet& fset, Position from, Position to,bool& inCheck)
{

    Field* fieldFrom=board.getField(from.x,from.y);
    Field* fieldTo=board.getField(to.x,to.y);
    Figure* stepFigure=fieldFrom->getFigure();
    Figure* hitFigure=fieldTo->getFigure();
    if (hitFigure!=NULL)
    {
        hitFigure->setField(NULL);
    }
    fieldFrom->setFigure(NULL);
    stepFigure->setField(fieldTo);
    fieldTo->setFigure(stepFigure);
    Figure* king= fset.getKing();
    inCheck=checkAttack(king);
    if(inCheck)
    {
        if (hitFigure!=NULL)
        {
            hitFigure->setField(fieldTo);
        }
        fieldFrom->setFigure(stepFigure);
        stepFigure->setField(fieldFrom);
        fieldTo->setFigure(hitFigure);
        system("cls");
        draw();
        drawMenu("Check");
        return false;
    }
    return true;
};

void DemChess::draw()
{
   board.draw();

};

void DemChess::drawMenu(const char* c)
{
   std::cout<<c<<endl;
   std::cout<<"Move: W/A/S/D"<<endl;
   //std::cout<<"Save: M"<<endl;
   std::cout<<"Give up: G"<<endl;
   std::cout<<"Select/Unselect: SPACE"<<endl;

}

/*void DemChess::saveGame()
{
    FILE* f;
    f=fopen("chess.txt","w");
    for(unsigned int i=0; i<whiteFigures.size();i++)
    {
        fprintf(f,"%d    ",whiteFigures[i]->getField()->getPos().getX());
        fprintf(f,"%d\n",whiteFigures[i]->getField()->getPos().getY());
    }
    //fprintf(f,"\n");
    for(unsigned int i=0; i<blackFigures.size();i++)
    {
        fprintf(f,"%d    ",blackFigures[i]->getField()->getPos().getX());
        fprintf(f,"%d\n",blackFigures[i]->getField()->getPos().getY());
    }
}
*/

bool DemChess::checkAttack(Figure* figure)
{
    FigureSet fset= figure->getColor()==WHITE ? blackFigures : whiteFigures;
    for(unsigned int i=0; i<fset.size();i++)
    {
        if(fset[i]->getField()!=NULL)
        {
            FieldList fList=fset[i]->whereToHit();

            FieldList::iterator it = std::find(fList.begin()
                                          ,fList.end()
                                          ,figure->getField());
            if(it!=fList.end())
                return true;
        }
    }
    return false;
}

bool DemChess::getManMove(FigureSet& currentPlayer, Position& from, Position& to)
{
    Field* cursoredField=board.getField(0,0);
    cursoredField->setCursor(true);
    char x='w';
    const char* error="";
    bool selected=false;
    bool moved=false;
    while(moved!=true)
    {
        system("cls");
        draw();
        drawMenu(error);
        x=getch();
        switch(x)
        {
        case 'w':
        {
            cursoredField->setCursor(false);
            if(cursoredField->getPos().x==0)
            {
                cursoredField=board.getField(BOARDSIZE-1,cursoredField->getPos().y);
            }
            else
            {
                cursoredField=board.getField(cursoredField->getPos().addToPos(-1,0).x
                                            ,cursoredField->getPos().addToPos(-1,0).y);
            }
            cursoredField->setCursor(true);
            break;
        }
        case 'a':
        {
            cursoredField->setCursor(false);
            if(cursoredField->getPos().y==0)
            {
                cursoredField=board.getField(cursoredField->getPos().x,BOARDSIZE-1);
            }
            else
            {
                cursoredField=board.getField(cursoredField->getPos().addToPos(0,-1).x
                                            ,cursoredField->getPos().addToPos(0,-1).y);
            }
            cursoredField->setCursor(true);
            break;
        }
        case 's':
        {
            cursoredField->setCursor(false);
            if(cursoredField->getPos().x==BOARDSIZE-1)
            {
                cursoredField=board.getField(0,cursoredField->getPos().y);
            }
            else
            {
            cursoredField=board.getField(cursoredField->getPos().addToPos(1,0).x
                                        ,cursoredField->getPos().addToPos(1,0).y);
            }
            cursoredField->setCursor(true);
            break;
        }
        case 'd':
        {
            cursoredField->setCursor(false);
            if(cursoredField->getPos().y==BOARDSIZE-1)
            {
                cursoredField=board.getField(cursoredField->getPos().x,0);
            }
            else
            {
            cursoredField=board.getField(cursoredField->getPos().addToPos(0,1).x
                                        ,cursoredField->getPos().addToPos(0,1).y);
            }
            cursoredField->setCursor(true);
            break;
        }
        case 'b':
        {
            break;
        }
        case 'm':
        {
           // saveGame();
            break;
        }
        case 'g':
        {
            return false;
            break;
        }
        case ' ':
        {
            if(selected!=true)
            {
                FigureSet::iterator it = std::find(currentPlayer.begin()
                                                  ,currentPlayer.end()
                                                  ,cursoredField->getFigure());
                if(it!=currentPlayer.end())
                {

                    cursoredField->getFigure()->setSelected(true);
                    from.x=cursoredField->getPos().x;
                    from.y=cursoredField->getPos().y;
                    selected=true;
                    break;
                }
                else
                {
                    error="Choose your OWN figure!!!";
                    std::cout<<"Choose your OWN figure!!!"<<endl;
                }
            }
            else
            {
                if(cursoredField->getFigure()!=NULL&&cursoredField->getFigure()->getSelected()==true)
                {
                    cursoredField->getFigure()->setSelected(false);
                    selected=false;
                    break;
                }
                else
                {
                    FieldList fieldList=board.getField(from.x,from.y)->getFigure()->whereToStep();
                    FieldList::iterator iter = std::find(fieldList.begin()
                                                      ,fieldList.end()
                                                      ,cursoredField);
                    if(iter!=fieldList.end())
                    {
                        board.getField(from.x,from.y)->getFigure()->setSelected(false);
                        cursoredField->setCursor(false);
                        to.x=cursoredField->getPos().x;
                        to.y=cursoredField->getPos().y;
                        moved=true;
                        break;
                    }
                    else
                    {

                         error="You can't move there!!!";
                         std::cout<<"You can't move there!!!"<<endl;
                    }
                }

            }
        }
        }
    }

        system("cls");
        draw();

    return (board.checkPos(from)&&board.checkPos(to));
}


bool DemChess::getAutMove(FigureSet& currentPlayer,Position& from, Position& to)
{

    for(int i=0;i<100;i++)
    {
        int r=rand() %currentPlayer.size();
        if(currentPlayer[r]->getField()!=NULL)
        {
            FieldList fieldList=currentPlayer[r]->whereToStep();
            if(fieldList.size()>0)
            {
                int l=rand() %fieldList.size();
                from=currentPlayer[r]->getField()->getPos();
                to=fieldList[l]->getPos();
                return true;
            }
        }
    }
    return false;
}

DemChess::~DemChess()
{
    for(unsigned int i=0; i<whiteFigures.size();i++)
    {
        delete whiteFigures[i];
    }
    for(unsigned int i=0; i<blackFigures.size();i++)
    {
        delete blackFigures[i];
    }
}

