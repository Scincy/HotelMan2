
#include "Room.h"
char* GetRoomNumber(Room room) {
    if (room.floorLevel >= 100 || room.story >= 100 || room.floorLevel <= 0 || room.story <= 0)
    {
        printf("\n\n----------");
        printf("�� ������ �߸���! �̻��� ��ȣ�� ���� �־��\n");
        printf("----------\n");
    }

    char* roomNumStr = (char*)malloc(5 * sizeof(char)); // 4�ڸ� �� ��ȣ + NULL ���� ����

    if (!roomNumStr) {
        printf("�޸� �Ҵ� ����\n");
        return NULL;
    }

    // ������ 10 �̸��� ��� 10�� �ڸ��� ��������, �׷��� ������ ������ ������
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