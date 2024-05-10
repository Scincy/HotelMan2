#pragma once
struct RoomService
{
	char* name;
	int price;
	int serveCount;
};

struct RoomServiceList {
	struct RoomService* services;
	int size;
	int capacity;
};
// �迭 �ʱ�ȭ
void initRoomServiceList(struct RoomServiceList* list, int initialCapacity);

// �� ���� �߰�, ���񽺰� ����Ʈ ���� �����ϸ� ���� Ȥ���ؼ� �߰�, ����Ʈ�� �����ٸ� ���� �����Ҵ�
void addRoomService(struct RoomServiceList* list, const char* name, int price, int serveCount);

// �� ���� ����, ���񽺰� ����Ʈ ���� �����ϸ� ����Ȯ���ؼ� ����, ���� ���̱� ����
void removeRoomService(struct RoomServiceList* list, int index);

// �迭 �޸� ����
void freeRoomServiceList(struct RoomServiceList* list);

// �迭�� ��� ���
void printRoomServices(const struct RoomServiceList* list);