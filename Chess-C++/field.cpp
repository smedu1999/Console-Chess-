#include "field.h"
#include <iostream>
#include "figure.h"

using namespace std;

void Field::draw()
{
    if (this->figure==NULL)
    {
        if (this->hasCursor==true)
        {
            if (this->pos.y!=8)
                std::cout<<"| ***** |";
        }
        if (this->hasCursor==false)
        {
            if (this->pos.y!=8)
                std::cout<<"|       |";
        }
        if (this->pos.y==7)
        {
            std::cout<<endl<<endl;
            for(int i=0;i<8;i++)
                std::cout<<"|_______|";
            std::cout<<endl;
        }

    }
    else
        this->figure->draw();
}

