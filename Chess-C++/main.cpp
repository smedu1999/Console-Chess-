#include <iostream>
#include "test.h"
#include "gtest_lite.h"
using namespace std;
char mainMenu()
{

    std::cout<<"(N)New Game"<<endl;
    std::cout<<"(O)Options"<<endl;
    std::cout<<"(X)Exit"<<endl;
    char x;
    std::cin>>x;
    switch(tolower(x))
    {
    case 'n':
    {
        DemChess chess;
        chess.playGame();
        break;
    }
    case 'o':
    {
        char y;
        system("cls");
        std::cout<<"(C)Computer-Player"<<endl;
        std::cout<<"(P)Player-Player"<<endl;
        std::cout<<"(A)Computer-Computer"<<endl;
        std::cin>>y;
        if(y=='c')
        {
            DemChess chess(MANUAL, AUTO);
            chess.playGame();
        }
        if(y=='p')
        {
            DemChess chess(MANUAL, MANUAL);
            chess.playGame();
        }
        if(y=='a')
        {
            DemChess chess(AUTO, AUTO);
            chess.playGame();
        }
        break;
    }
    case 'x':
    {
        break;
    }

    }
    return x;
};



int main()
{
    TEST(testFigure, Rook)
       EXPECT_EQ(true, ChessTest::testRook());
    END
    TEST(testFigure, Pawn)
       EXPECT_EQ(true, ChessTest::testPawn());
    END
    TEST(testFigure, Knight)
       EXPECT_EQ(true, ChessTest::testKnight());
    END
    TEST(testFigure, King)
       EXPECT_EQ(true, ChessTest::testKing());
    END
    TEST(testFigure, Queen)
       EXPECT_EQ(true, ChessTest::testQueen());
    END
    TEST(testFigure, Bishop)
       EXPECT_EQ(true, ChessTest::testBishop());
    END
   while(true)
    {
        if(mainMenu()=='x')
        {

            return 0;

        }
    }
    return 0;
}
