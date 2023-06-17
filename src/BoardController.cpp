#include "BoardController.h"

BoardController::BoardController()
{
  start_color(); // ncurses 라이브러리에서 제공하는 함수로, 터미널에서 컬러를 사용할 수 있게 해줍니다.

  main_board = newwin(30, 60, 5, 10); // 30x60 크기의 새 창을 생성하고, 터미널의 (5,10) 위치에 놓습니다. 이 창을 main_board로 지칭합니다.

  wbkgd(main_board, COLOR_PAIR(2)); // main_board의 배경색을 설정합니다. COLOR_PAIR(2)는 이전에 정의된 컬러 페어를 가리킵니다.

  score_board = newwin(15, 40, 5, 73); // 15x40 크기의 새 창을 생성하고, 터미널의 (5,73) 위치에 놓습니다. 이 창을 score_board로 지칭합니다.

  wbkgd(score_board, COLOR_PAIR(1)); // score_board의 배경색을 설정합니다. COLOR_PAIR(1)는 이전에 정의된 컬러 페어를 가리킵니다.

  wattron(score_board, COLOR_PAIR(1)); // score_board에 대해 컬러 페어 1을 활성화합니다. 이후에 이 창에 출력되는 텍스트는 이 컬러를 사용합니다.

  mvwprintw(score_board, 0, 14, "Score Board"); // score_board 창의 (0,14) 위치에 "Score Board"라는 문자열을 출력합니다.

  mission_board = newwin(12, 40, 23, 73); // 12x40 크기의 새 창을 생성하고, 터미널의 (23,73) 위치에 놓습니다. 이 창을 mission_board로 지칭합니다.

  wbkgd(mission_board, COLOR_PAIR(1)); // mission_board의 배경색을 설정합니다. COLOR_PAIR(1)는 이전에 정의된 컬러 페어를 가리킵니다.

  wattron(mission_board, COLOR_PAIR(1)); // mission_board에 대해 컬러 페어 1을 활성화합니다. 이후에 이 창에 출력되는 텍스트는 이 컬러를 사용합니다.

  mvwprintw(mission_board, 0, 14, "Mission Board"); // mission_board 창의 (0,14) 위치에 "Mission Board"라는 문자열을 출력합니다.
}
