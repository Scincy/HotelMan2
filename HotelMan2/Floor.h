#pragma once
#define RoomCountInAFloor 20

#include "Room.h"
typedef struct Floor
{
    int level;
    Room* rooms;
}Floor;

void InitializeFloor(Floor* floor, int floorlevel);