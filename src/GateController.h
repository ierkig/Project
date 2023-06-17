#include "Map.h"
#include <cstdlib>
#include <ctime>
#include "util.h"
#include <iostream>
#include "Snake.h"
#include "BoardController.h"

using namespace std;

// 게이트 클래스 정의
class Gate
{
public:
    Map &gateMap;                                                         // 게이트 맵에 대한 참조
    Snake &snake;                                                         // 스네이크 객체에 대한 참조
    vector<pair<int, int>> gateList;                                      // 게이트 리스트
    pair<int, int> &gate1;                                                // 게이트1에 대한 참조
    pair<int, int> &gate2;                                                // 게이트2에 대한 참조
    int &command;                                                         // 사용자의 명령에 대한 참조
    int &usedGateCount;                                                   // 사용된 게이트의 수에 대한 참조
    BoardController &board;                                               // 보드 컨트롤러에 대한 참조
    int &goal_gateCount;                                                  // 목표 게이트 개수에 대한 참조
    string mission_gateCount = "G:" + to_string(goal_gateCount) + " (V)"; // 게이트 목표 개수를 문자열로 변환
    // 게이트 생성자
    Gate(Map &map, Snake &snake, int &command, int &usedGateCount, BoardController &board, pair<int, int> &gate1, pair<int, int> &gate2, int &goal_gateCount) : gateMap(map), snake(snake), command(command), usedGateCount(usedGateCount), board(board), gate1(gate1), gate2(gate2), goal_gateCount(goal_gateCount){};

    // 게이트 맵 동기화 함수
    void syncMap();

    // 게이트 새로고침 함수
    void gateRefresh();

    // 게이트 센서 함수
    void gateSensor();
};
