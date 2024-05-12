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
    struct RoomServiceList list;
}Room;
char* GetRoomNumber(Room room);

int GetRoomPrice(Room room);
