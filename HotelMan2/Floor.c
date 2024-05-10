#include "Floor.h"
void InitializeFloor(Floor* floor, int floorlevel)
{
    floor->rooms = malloc(sizeof(Room) * RoomCountInAFloor);

    for (int i = 0; i < RoomCountInAFloor; i++)
    {
        floor->rooms[i].occupy = false;
        floor->rooms[i].floorLevel = floorlevel;
        floor->rooms[i].story = i + 1;
    }
}