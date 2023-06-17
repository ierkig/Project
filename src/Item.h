class Item
{
public:
    int x;         // 아이템의 x좌표
    int y;         // 아이템의 y좌표
    bool itemType; // 아이템의 타입 (참/거짓 값으로 표현)
    int lifeTime;  // 아이템의 수명 (게임 내에 존재하는 시간)
    // 생성자: 좌표, 아이템 타입, 수명을 받아서 아이템 객체를 생성
    Item(int x, int y, bool itemType, int lifeTime = 5) : x(x), y(y), itemType(itemType), lifeTime(lifeTime){};
};