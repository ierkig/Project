#include <ncurses.h> 

#ifndef BOARD 
#define BOARD 

class BoardController
{
public:
    WINDOW *main_board, *score_board, *mission_board; // WINDOW는 ncurses에서 제공하는 데이터 타입으로, 터미널 창을 추상화한 것입니다. 이 클래스는 세 개의 WINDOW 포인터를 멤버로 가집니다.

    BoardController(); // BoardController 클래스의 생성자를 선언합니다. 이 생성자는 클래스의 객체가 생성될 때 호출됩니다.
};

#endif 
