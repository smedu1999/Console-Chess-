#include "figure.h"
#include "field.h"
#include <iostream>
#include <algorithm>
#include "board.h"

using namespace std;


Figure::Figure(Field* field, Color c):field(field), c(c), selected(false)
{
    field->setFigure(this);
}


void Pawn::draw()
{
    if (getField()->getHasCursor()==true)
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|/*WPa*/|";
            }
            if(getColor()==BLACK)
                std::cout<<"|/*BPa*/|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"| *WPa* |";
            }
            if(getColor()==BLACK)
                std::cout<<"| *BPa* |";
        }
    }
    else
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|//WPa//|";
            }
            if(getColor()==BLACK)
                std::cout<<"|//BPa//|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|  WPa  |";
            }
            if(getColor()==BLACK)
                std::cout<<"|  BPa  |";
        }
    }


    if (getField()->getPos().y==7)
    {
        std::cout<<endl<<endl;
        for(int i=0;i<8;i++)
            std::cout<<"|_______|";
        std::cout<<endl;
    }
};

void Knight::draw()
{
    if (getField()->getHasCursor()==true)
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|/*WKn*/|";
            }
            if(getColor()==BLACK)
                std::cout<<"|/*BKn*/|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"| *WKn* |";
            }
            if(getColor()==BLACK)
                std::cout<<"| *BKn* |";
        }
    }
    else
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|//WKn//|";
            }
            if(getColor()==BLACK)
                std::cout<<"|//BKn//|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|  WKn  |";
            }
            if(getColor()==BLACK)
                std::cout<<"|  BKn  |";
        }
    }


    if (getField()->getPos().y==7)
    {
        std::cout<<endl<<endl;
        for(int i=0;i<8;i++)
            std::cout<<"|_______|";
        std::cout<<endl;
    }
};

void Queen::draw()
{
    if (getField()->getHasCursor()==true)
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|/*WQu*/|";
            }
            if(getColor()==BLACK)
                std::cout<<"|/*BQu*/|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"| *WQu* |";
            }
            if(getColor()==BLACK)
                std::cout<<"| *BQu* |";
        }
    }
    else
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|//WQu//|";
            }
            if(getColor()==BLACK)
                std::cout<<"|//BQu//|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|  WQu  |";
            }
            if(getColor()==BLACK)
                std::cout<<"|  BQu  |";
        }
    }


    if (getField()->getPos().y==7)
    {
        std::cout<<endl<<endl;
        for(int i=0;i<8;i++)
            std::cout<<"|_______|";
        std::cout<<endl;
    }
};

void King::draw()
{
    if (getField()->getHasCursor()==true)
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|/*WKi*/|";
            }
            if(getColor()==BLACK)
                std::cout<<"|/*BKi*/|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"| *WKi* |";
            }
            if(getColor()==BLACK)
                std::cout<<"| *BKi* |";
        }
    }
    else
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|//WKi//|";
            }
            if(getColor()==BLACK)
                std::cout<<"|//BKi//|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|  WKi  |";
            }
            if(getColor()==BLACK)
                std::cout<<"|  BKi  |";
        }
    }


    if (getField()->getPos().y==7)
    {
        std::cout<<endl<<endl;
        for(int i=0;i<8;i++)
            std::cout<<"|_______|";
        std::cout<<endl;
    }
};



void Rook::draw()
{
    if (getField()->getHasCursor()==true)
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|/*WRo*/|";
            }
            if(getColor()==BLACK)
                std::cout<<"|/*BRo*/|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"| *WRo* |";
            }
            if(getColor()==BLACK)
                std::cout<<"| *BRo* |";
        }
    }
    else
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|//WRo//|";
            }
            if(getColor()==BLACK)
                std::cout<<"|//BRo//|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|  WRo  |";
            }
            if(getColor()==BLACK)
                std::cout<<"|  BRo  |";
        }
    }


    if (getField()->getPos().y==7)
    {
        std::cout<<endl<<endl;
        for(int i=0;i<8;i++)
            std::cout<<"|_______|";
        std::cout<<endl;
    }
};


void Bishop::draw()
{
    if (getField()->getHasCursor()==true)
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|/*WBi*/|";
            }
            if(getColor()==BLACK)
                std::cout<<"|/*BBi*/|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"| *WBi* |";
            }
            if(getColor()==BLACK)
                std::cout<<"| *BBi* |";
        }
    }
    else
    {
        if(getSelected())
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|//WBi//|";
            }
            if(getColor()==BLACK)
                std::cout<<"|//BBi//|";
        }
        else
        {
            if(getColor()==WHITE)
            {
                std::cout<<"|  WBi  |";
            }
            if(getColor()==BLACK)
                std::cout<<"|  BBi  |";
        }
    }


    if (getField()->getPos().y==7)
    {
        std::cout<<endl<<endl;
        for(int i=0;i<8;i++)
            std::cout<<"|_______|";
        std::cout<<endl;
    }
};

void Figure::generateSteps(FieldList& fieldList, int dx, int dy, int maxMove)
{
    Position pos=getField()->getPos();
    Board* board=field->getBoard();
    for(int i=0; i<maxMove;i++)
    {
        pos.x+=dx;
        pos.y+=dy;
        if(!(board->checkPos(pos)))
        {
           return;
        }
        Field* newField=board->getField(pos.x,pos.y);
        Figure* fig=newField->getFigure();
        if(fig!=NULL)
        {
            if(fig->getColor()==c)
                return;
            if(fig->getColor()!=c)
            {
                fieldList.push_back(newField);
                return;
            }
        }
        else
        {
            fieldList.push_back(newField);
        }

    }
}
FieldList Pawn::whereToStep()
{
    int dir= getColor()==WHITE ? +1 : -1;
    FieldList fieldList;
    Position currentPos=getField()->getPos();
    Field* frontField=getField()->getBoard()->getField(currentPos.x+dir,currentPos.y);
    Field* frontFrontField=getField()->getBoard()->getField(currentPos.x+dir,currentPos.y);
    Field* rightCrossField=getField()->getBoard()->getField(currentPos.x+dir,currentPos.y+1);
    Field* leftCrossField=getField()->getBoard()->getField(currentPos.x+dir,currentPos.y-1);
    if(currentPos.x+dir<BOARDSIZE&&currentPos.x+dir>=0)
    {
        if(frontField!=NULL&&frontFrontField!=NULL&&(currentPos.x==1||currentPos.x==6)&&frontField->getFigure()==NULL&&frontFrontField->getFigure()==NULL&&(currentPos.x+2*dir<BOARDSIZE&&currentPos.x+2*dir>0))
            fieldList.push_back(getField()->getBoard()->getField(currentPos.x+2*dir,currentPos.y));
        if(frontField!=NULL&&frontField->getFigure()==NULL)
            fieldList.push_back(getField()->getBoard()->getField(currentPos.x+dir,currentPos.y));
        if(rightCrossField!=NULL&&rightCrossField->getFigure()!=NULL&&rightCrossField->getFigure()->getColor()!=getColor())
            fieldList.push_back(getField()->getBoard()->getField(currentPos.x+dir,currentPos.y+1));
        if(leftCrossField!=NULL&&leftCrossField->getFigure()!=NULL&&leftCrossField->getFigure()->getColor()!=getColor())
            fieldList.push_back(getField()->getBoard()->getField(currentPos.x+dir,currentPos.y-1));
    }
    return fieldList;
}

FieldList Knight::whereToStep()
{
    FieldList fieldList;
    generateSteps(fieldList,-1,+2,1);
    generateSteps(fieldList,+1,+2,1);
    generateSteps(fieldList,-1,-2,1);
    generateSteps(fieldList,+1,-2,1);
    generateSteps(fieldList,+2,-1,1);
    generateSteps(fieldList,+2,+1,1);
    generateSteps(fieldList,-2,-1,1);
    generateSteps(fieldList,-2,+1,1);
    return fieldList;
}
FieldList King::whereToStep()
{
    FieldList fieldList;
    generateSteps(fieldList,-1,-1,1);
    generateSteps(fieldList,+1,-1,1);
    generateSteps(fieldList,-1,+1,1);
    generateSteps(fieldList,+1,+1,1);
    generateSteps(fieldList, 0,-1,1);
    generateSteps(fieldList,+1, 0,1);
    generateSteps(fieldList,-1, 0,1);
    generateSteps(fieldList, 0,+1,1);
    return fieldList;
}

FieldList Bishop::whereToStep()
{
    FieldList fieldList;
    generateSteps(fieldList,-1,-1,BOARDSIZE);
    generateSteps(fieldList,+1,-1,BOARDSIZE);
    generateSteps(fieldList,-1,+1,BOARDSIZE);
    generateSteps(fieldList,+1,+1,BOARDSIZE);

    return fieldList;
}

FieldList Rook::whereToStep()
{
    FieldList fieldList;
    generateSteps(fieldList, 0,-1,BOARDSIZE);
    generateSteps(fieldList,+1, 0,BOARDSIZE);
    generateSteps(fieldList,-1, 0,BOARDSIZE);
    generateSteps(fieldList, 0,+1,BOARDSIZE);

    return fieldList;
}

FieldList Queen::whereToStep()
{
    FieldList fieldList;
    generateSteps(fieldList,-1,-1,BOARDSIZE);
    generateSteps(fieldList,+1,-1,BOARDSIZE);
    generateSteps(fieldList,-1,+1,BOARDSIZE);
    generateSteps(fieldList,+1,+1,BOARDSIZE);
    generateSteps(fieldList, 0,-1,BOARDSIZE);
    generateSteps(fieldList,+1, 0,BOARDSIZE);
    generateSteps(fieldList,-1, 0,BOARDSIZE);
    generateSteps(fieldList, 0,+1,BOARDSIZE);

    return fieldList;
}
FieldList Pawn::whereToHit()
{
    FieldList fieldList;
    int dir= getColor()==WHITE ? +1 : -1;
    Position currentPos=getField()->getPos();
    fieldList.push_back(getField()->getBoard()->getField(currentPos.x+dir,currentPos.y+1));
    fieldList.push_back(getField()->getBoard()->getField(currentPos.x+dir,currentPos.y-1));

    return fieldList;
}
FieldList Knight::whereToHit()
{
    FieldList fieldList=whereToStep();
    return fieldList;
}
FieldList King::whereToHit()
{
    FieldList fieldList=whereToStep();
    return fieldList;
}
FieldList Queen::whereToHit()
{
    FieldList fieldList=whereToStep();
    return fieldList;
}
FieldList Bishop::whereToHit()
{
    FieldList fieldList=whereToStep();
    return fieldList;
}
FieldList Rook::whereToHit()
{
    FieldList fieldList=whereToStep();
    return fieldList;
}

void FigureSet::winGame()
{
    if(king->getColor()==BLACK)
    {
        //system("cls");
        std::cout<<"\n";
        std::cout<<"                              @@@@@@@    @@@@@@@@@@@@@@@@@    @@@@@@@"<<endl;
        std::cout<<"                               @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@"<<endl;
        std::cout<<"                                @@@*       @@@@     @@@@       /@@@"<<endl;
        std::cout<<"                                 @@@(       @@@@   @@@@       (@@@"<<endl;
        std::cout<<"                                  @@@#       @@@@ @@@@       #@@@"<<endl;
        std::cout<<"                                   @@@&       @@@@@@@       &@@@"<<endl;
        std::cout<<"                                    @@@&       @@@@@       &@@@"<<endl;
        std::cout<<"                                     @@@&      @@@@@      &@@@"<<endl;
        std::cout<<"                                      @@@@    @@@@@@@    @@@@"<<endl;
        std::cout<<"                                       @@@@  @@@@ @@@@  @@@@"<<endl;
        std::cout<<"                                        @@@@@@@@   @@@@@@@@"<<endl;
        std::cout<<"                                         @@@@@@     @@@@@@"<<endl;
        std::cout<<"                                          @@@@       @@@@"<<endl;
        std::cout<<"                                           @@         @@"<<endl;
        std::cout<<"                                            Press space                                    "<<endl;
        std::cout<<"                                              for new                                   "<<endl;
        std::cout<<"                                               game                                "<<endl;
        std::cout<<"              @@   &@@   @@     @@     @@#   @@     @@@   .@&     @@@@@@@    #@@@@@@/"<<endl;
        std::cout<<"              &@&  @@@* .@@     @@     @@@@  @@     @@@@* .@&     @@         #@(   @@"<<endl;
        std::cout<<"               @@ @@ @@ @@      @@     @@ @@&@@     @@ /@@.@&     @@@@@@     #@@@@@@@"<<endl;
        std::cout<<"                @@@   @@@       @@     @@   @@@     @@   @@@&     @@         #@( *@@"<<endl;
        std::cout<<"                (@&   /@@       @@     @@    @@     @@    ,@&     @@@@@@@    #@(   @@"<<endl;
    }
    else
    {
        //system("cls");
        cout<<"                                          @@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@        @@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@   Press  @@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@   space  @@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@         @@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@         @@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@  for new  @@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@    game    @@@@@@@"<<endl;
        cout<<"                                       @@@@@@@          @@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@@@@@@@"<<endl;
        cout<<"                                       @@@@@@@@@@@@@@@@#"<<endl;
        cout<<"                                                                                           "<<endl;
        cout<<"                                                                                "<<endl;
        cout<<"                                                                               "<<endl;
        cout<<"              @@   &@@   @@     @@     @@#   @@     @@@   .@&     @@@@@@@    #@@@@@@/"<<endl;
        cout<<"              &@&  @@@* .@@     @@     @@@@  @@     @@@@* .@&     @@         #@(   @@"<<endl;
        cout<<"               @@ @@ @@ @@      @@     @@ @@&@@     @@ /@@.@&     @@@@@@     #@@@@@@@"<<endl;
        cout<<"                @@@   @@@       @@     @@   @@@     @@   @@@&     @@         #@( *@@"<<endl;
        cout<<"                (@&   /@@       @@     @@    @@     @@    ,@&     @@@@@@@    #@(   @@"<<endl;
    }
    getch();

}
