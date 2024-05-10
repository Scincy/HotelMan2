#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "RoomService.h"


void initRoomServiceList(struct RoomServiceList* list, int initialCapacity) {
    list->services = (struct RoomService*)malloc(initialCapacity * sizeof(struct RoomService));
    list->size = 0;
    list->capacity = initialCapacity;
}


bool checkDuplicate(const struct RoomServiceList* list, const char* name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->services[i].name, name) == 0) {
            return true;  // �ߺ��� �̸��� �߰ߵǸ� true ��ȯ
        }
    }
    return false;  // �ߺ��� �̸��� ������ false ��ȯ
}

/// <summary>
/// 
/// </summary>
/// <param name="list">�����Ҵ� ����ü �迭</param>
/// <param name="name">�߰��Ϸ��� �ϴ� ������ �̸�</param>
/// <param name="price">�߰��Ϸ��� �ϴ� ������ �ܰ�</param>
/// <param name="serveCount">�߰��Ϸ��� �ϴ� ������ ���� Ƚ��</param>
void addRoomService(struct RoomServiceList* list, const char* name, int price, int serveCount) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->services[i].name, name) == 0) {
            // �ߺ��� �̸��� ã�� ��� serveCount�� ������Ʈ
            list->services[i].serveCount += serveCount;
            return;
        }
    }
    // �ߺ��� �̸��� ���� ��� ���ο� ��� �߰�
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->services = (struct RoomService*)realloc(list->services, list->capacity * sizeof(struct RoomService));
    }
    list->services[list->size].name = strdup(name);
    list->services[list->size].price = price;
    list->services[list->size].serveCount = serveCount;
    list->size++;
}


void removeRoomService(struct RoomServiceList* list, const char* name, int count) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->services[i].name, name) == 0) {
            list->services[i].serveCount -= count;  // serveCount ����
            if (list->services[i].serveCount <= 0) {
                // serveCount�� 0 ���ϰ� �Ǹ� ��� ����
                free(list->services[i].name);  // �̸��� �Ҵ�� �޸� ����
                // �迭���� ��� ����
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

// �迭�� ��� ���
void printRoomServices(const struct RoomServiceList* list) {
    printf("Room Services:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d: %s, Price: %d, Serve Count: %d\n", i, list->services[i].name, list->services[i].price, list->services[i].serveCount);
    }
}