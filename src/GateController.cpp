#include "GateController.h"

void Gate::syncMap()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      if (gateMap.m[i][j] == 1)
      {
        gateList.push_back(pair<int, int>(i, j));
      }
    }
  }
}

void Gate::gateRefresh()
{
  int gateChoice1, gateChoice2;

  gateChoice1 = rand() % (gateList.size()); // 게이트 리스트에서 랜덤으로 첫 번째 게이트 선택
  gateChoice2 = rand() % (gateList.size()); // 게이트 리스트에서 랜덤으로 두 번째 게이트 선택

  while (gateChoice1 == gateChoice2)
  {
    gateChoice2 = rand() % (gateList.size()); // 두 번째 게이트가 첫 번째 게이트와 중복되지 않도록 선택
  }

  gate1 = make_pair(gateList[gateChoice1].first, gateList[gateChoice1].second); // 선택된 좌표로 첫 번째 게이트 설정
  gate2 = make_pair(gateList[gateChoice2].first, gateList[gateChoice2].second); // 선택된 좌표로 두 번째 게이트 설정

  gateMap.m[gate1.first][gate1.second] = GATE_COUNT; // 첫 번째 게이트의 위치를 게이트 개수로 표시
  gateMap.m[gate2.first][gate2.second] = GATE_COUNT; // 두 번째 게이트의 위치를 게이트 개수로 표시
}

void Gate::gateSensor()
{
  if (snake.body[0][0] == gate1.first && snake.body[0][1] == gate1.second) // 뱀 머리가 첫 번째 게이트에 도착한 경우
  {
    usedGateCount++; // 사용된 게이트 개수 증가
    if (gate2.first == 0)
    {
      command = 4; // 두 번째 게이트가 맵의 위쪽에 있을 때 아래쪽으로 이동
    }
    else if (gate2.first == 29)
    {
      command = 1; // 두 번째 게이트가 맵의 아래쪽에 있을 때 위쪽으로 이동
    }
    else if (gate2.second == 0)
    {
      command = 2; // 두 번째 게이트가 맵의 왼쪽에 있을 때 오른쪽으로 이동
    }
    else if (gate2.second == 59)
    {
      command = 3; // 두 번째 게이트가 맵의 오른쪽에 있을 때 왼쪽으로 이동
    }
    else
    {
      if (gate1.first != gate2.first && gate1.second != gate2.second)
      {
        if (command == 3)
        {
          command = 1; // 두 번째 게이트가 첫 번째 게이트와 수직인 경우, 위쪽으로 이동
        }
        else if (command == 2)
        {
          command = 4; // 두 번째 게이트가 첫 번째 게이트와 수직인 경우, 아래쪽으로 이동
        }
        else if (command == 1)
        {
          command = 2; // 두 번째 게이트가 첫 번째 게이트와 수평인 경우, 오른쪽으로 이동
        }
        else if (command == 4)
        {
          command = 3; // 두 번째 게이트가 첫 번째 게이트와 수평인 경우, 왼쪽으로 이동
        }
      }
    }
    snake.body[0][0] = gate2.first; // 뱀 머리의 좌표를 두 번째 게이트의 좌표로 변경
    snake.body[0][1] = gate2.second;
    string state4 = "G:" + to_string(usedGateCount);

    mvwprintw(board.score_board, 8, 5, state4.c_str());

    if (usedGateCount >= goal_gateCount)
    {
      mvwprintw(board.mission_board, 8, 5, mission_gateCount.c_str());
    }
  }
  else if (snake.body[0][0] == gate2.first && snake.body[0][1] == gate2.second) // 뱀 머리가 두 번째 게이트에 도착한 경우
  {
    usedGateCount++; // 사용된 게이트 개수 증가
    if (gate1.first == 0)
    {
      command = 4; // 첫 번째 게이트가 맵의 위쪽에 있을 때 아래쪽으로 이동
    }
    else if (gate1.first == 29)
    {
      command = 1; // 첫 번째 게이트가 맵의 아래쪽에 있을 때 위쪽으로 이동
    }
    else if (gate1.second == 0)
    {
      command = 2; // 첫 번째 게이트가 맵의 왼쪽에 있을 때 오른쪽으로 이동
    }
    else if (gate1.second == 59)
    {
      command = 3; // 첫 번째 게이트가 맵의 오른쪽에 있을 때 왼쪽으로 이동
    }
    else
    {
      if (gate1.first != gate2.first && gate1.second != gate2.second)
      {
        if (command == 3)
        {
          command = 1; // 첫 번째 게이트가 두 번째 게이트와 수직인 경우, 위쪽으로 이동
        }
        else if (command == 2)
        {
          command = 4; // 첫 번째 게이트가 두 번째 게이트와 수직인 경우, 아래쪽으로 이동
        }
        else if (command == 1)
        {
          command = 2; // 첫 번째 게이트가 두 번째 게이트와 수평인 경우, 오른쪽으로 이동
        }
        else if (command == 4)
        {
          command = 3; // 첫 번째 게이트가 두 번째 게이트와 수평인 경우, 왼쪽으로 이동
        }
      }
    }
    snake.body[0][0] = gate1.first; // 뱀 머리의 좌표를 첫 번째 게이트의 좌표로 변경
    snake.body[0][1] = gate1.second;

    string state4 = "G:" + to_string(usedGateCount);
    mvwprintw(board.score_board, 8, 5, state4.c_str());
    if (usedGateCount >= goal_gateCount)
    {
      mvwprintw(board.mission_board, 8, 5, mission_gateCount.c_str());
    }
  }
}
