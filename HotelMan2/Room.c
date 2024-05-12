
#include "Room.h"
char* GetRoomNumber(Room room) {
    if (room.floorLevel >= 100 || room.story >= 100 || room.floorLevel <= 0 || room.story <= 0)
    {
        printf("\n\n----------");
        printf("방 설정이 잘못됨! 이상한 번호를 갖고 있어요\n");
        printf("----------\n");
    }

    char* roomNumStr = (char*)malloc(5 * sizeof(char)); // 4자리 방 번호 + NULL 종료 문자

    if (!roomNumStr) {
        printf("메모리 할당 실패\n");
        return NULL;
    }

    // 층수가 10 미만일 경우 10의 자리를 공백으로, 그렇지 않으면 정수로 포맷팅
    sprintf(roomNumStr, "%c%d%02d", (room.floorLevel < 10 ? ' ' : '0' + room.floorLevel / 10), room.floorLevel % 10, room.story);

    return roomNumStr;
}

int GetRoomPrice(Room room)
{
    int roomPrice = 0;
    switch (room.grade) {
    case 1:
        return (roomPrice = 150000);
    case 2:
        return (roomPrice = 250000);
    case 3:
        return (roomPrice = 350000);
    default:
        return roomPrice;
    }

}
int GetLevel(int IntengerRoomNumber) { return IntengerRoomNumber / 100; }
int GetStory(int IntengetRoomNumber) { return IntengetRoomNumber % 100; }