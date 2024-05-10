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
// 배열 초기화
void initRoomServiceList(struct RoomServiceList* list, int initialCapacity);

// 룸 서비스 추가, 서비스가 리스트 내에 존재하면 갯수 혹인해서 추가, 리드트에 없었다면 새로 동적할당
void addRoomService(struct RoomServiceList* list, const char* name, int price, int serveCount);

// 룸 서비스 삭제, 서비스가 리스트 내에 존재하면 갯수확인해서 삭제, 갯수 줄이기 결정
void removeRoomService(struct RoomServiceList* list, int index);

// 배열 메모리 해제
void freeRoomServiceList(struct RoomServiceList* list);

// 배열의 요소 출력
void printRoomServices(const struct RoomServiceList* list);