#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "RoomService.h"


void InitRoomServiceList(struct RoomServiceList* list, int initialCapacity) {
    list->services = (struct RoomService*)malloc(initialCapacity * sizeof(struct RoomService));
    list->size = 0;
    list->capacity = initialCapacity;
}


bool checkDuplicate(const struct RoomServiceList* list, const char* name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->services[i].name, name) == 0) {
            return true;  // 중복된 이름이 발견되면 true 반환
        }
    }
    return false;  // 중복된 이름이 없으면 false 반환
}


void addRoomService(struct RoomServiceList* list, struct RoomService newService) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->services[i].name, newService.name) == 0) {
            // 중복된 이름을 찾은 경우 serveCount만 업데이트
            list->services[i].serveCount += newService.serveCount;
            return;
        }
    }
    // 중복된 이름이 없을 경우 새로운 요소 추가
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->services = (struct RoomService*)realloc(list->services, list->capacity * sizeof(struct RoomService));
    }
    list->services[list->size].name = strdup(newService.name);
    list->services[list->size].price = newService.price;
    list->services[list->size].serveCount = newService.serveCount;
    list->size++;
}


void removeRoomService(struct RoomServiceList* list, const char* name, int count) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->services[i].name, name) == 0) {
            list->services[i].serveCount -= count;  // serveCount 감소
            if (list->services[i].serveCount <= 0) {
                // serveCount가 0 이하가 되면 요소 제거
                free(list->services[i].name);  // 이름에 할당된 메모리 해제
                // 배열에서 요소 제거
                for (int j = i; j < list->size - 1; j++) {
                    list->services[j] = list->services[j + 1];
                }
                list->size--;
                return;
            }
        }
    }
}



void freeRoomServiceList(struct RoomServiceList* list) {
    for (int i = 0; i < list->size; i++) {
        free(list->services[i].name);
    }
    free(list->services);
    list->services = NULL;
    list->size = 0;
    list->capacity = 0;
}

// 배열의 요소 출력
void printRoomServices(const struct RoomServiceList* list) {
    printf("Room Services:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d: %s, Price: %d, Serve Count: %d\n", i, list->services[i].name, list->services[i].price, list->services[i].serveCount);
    }
}