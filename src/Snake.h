#include <vector>

using namespace std;
#ifndef SNAKE
#define SNAKE
class Snake
{
public:
    // 뱀의 몸통을 표현하는 벡터 ((머리 x, 머리 y),(몸통 x, 몸통 y),(몸통)(몸통)...)
    vector<vector<int>> body;
    // 뱀의 크기, 기본값 = 3
    vector<int> empty_body{15, 30}; // 빈 몸통 위치를 초기화

    // 생성자
    Snake()
    {
        vector<int> head{2, 30};  // 뱀 머리의 초기 위치 설정
        vector<int> head2{2, 29}; // 뱀 몸통의 초기 위치 설정
        vector<int> head3{2, 28}; // 뱀 몸통의 초기 위치 설정
        body.push_back(head);     // 뱀의 몸통 벡터에 머리 추가
        body.push_back(head2);    // 뱀의 몸통 벡터에 몸통 추가
        body.push_back(head3);    // 뱀의 몸통 벡터에 몸통 추가
    };

    // 뱀의 크기 증가 함수
    void size_up()
    {
        body.push_back(empty_body); // 빈 몸통을 뱀의 몸통 벡터에 추가
    };

    // 뱀의 크기 감소 함수
    void size_down()
    {
        empty_body = body.back(); // 뱀의 몸통 벡터에서 마지막 원소를 empty_body로 설정
        body.pop_back();          // 뱀의 몸통 벡터에서 마지막 원소 제거
    };

    // 뱀의 움직임을 처리하는 함수
    void move(int command)
    {
        vector<int> tmp_head = body[0]; // 임시 머리 위치 설정
        vector<int> tmp;                // 임시 몸통 위치 설정

        // 머리부터 움직임
        switch (command)
        {
        case 1: // 위로
            body[0][0]--;
            body[0][0] = body[0][0] % 30;
            break;
        case 2: // 오른쪽으로
            body[0][1]++;
            body[0][1] = body[0][1] % 60;
            break;
        case 3: // 왼쪽으로
            body[0][1]--;
            if (body[0][1] < 0)
            {
                body[0][1] = 59;
            }
            body[0][1] = body[0][1] % 60;
            break;
        case 4: // 아래로
            body[0][0]++;
            body[0][0] = body[0][0] % 30;
            break;
        case 5: // 백스페이스(아무런 행동 없음)
            break;
        }

        // 몸통이 머리를 따라가는 부분
        for (vector<vector<int>>::iterator it = body.begin() + 1; it != body.end(); it++)
        {
            tmp = *it;
            *it = tmp_head;
            tmp_head = tmp;
        }
        empty_body[0] = tmp_head[0];
        empty_body[1] = tmp_head[1];
        // cout << empty_body[0] << empty_body[1] << endl; //디버깅을 위한 출력문 (필요 시 사용)
    }
};
#endif
