#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "RoomService.h"
typedef struct Room
{
    bool occupy;
    int grade;
    int floorLevel;
    int story;
    struct RoomServiceList serviceList;
}Room;
char* GetRoomNumber(Room room);

int GetRoomPrice(Room room);

int GetLevel(int IntengerRoomNumber);
int GetStory(int IntengetRoomNumber);