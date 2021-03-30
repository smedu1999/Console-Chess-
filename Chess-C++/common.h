#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include<iostream>
using namespace std;

struct Position
{
    int x;
    int y;
    bool operator==(Position& p) { return(x == p.x&&y == p.y); }
    Position& operator=(const Position& p) {x=p.x; y=p.y; return *this;}
    Position(int x=0, int y=0) :x(x),y(y) {}
    Position(const Position& p) :x(p.x), y(p.y) {}
    int getX() {return x;}
    int getY() {return y;}
    Position addToPos(int a, int b) {return Position(a+x,b+y);}
};

#ifndef WIN32
char getch();
#else
#include <conio.h>
#endif


enum Color {BLACK, WHITE};
enum PlayerType {MANUAL, AUTO};
const int BOARDSIZE = 8;










#endif // COMMON_H_INCLUDED
