//
// Created by Carlos Alves on 17/09/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


struct TStudent {
    int code;
    char name[30];
    float n1, n2, n3;
};

typedef struct TElement {
    TStudent students;
    struct TElement *next;
};

typedef struct TElement *TLinkedList;

TLinkedList *createLinkedList();

void clearLinkedList(TLinkedList *li);

int insertEndList(TLinkedList *li, struct TStudent student);

int insertStartList(TLinkedList *li, struct TStudent student);

int insertOrdenedList(TLinkedList *li, struct TStudent student);

int removeList(TLinkedList *li, int code);

int removeStartList(TLinkedList *li);

int removeEndList(TLinkedList *li);

int getSizeList(TLinkedList *li);

int isEmptyList(TLinkedList *li);

int isFullList(TLinkedList *li);

void printList(TLinkedList *li);

int findListByCode(TLinkedList *li, int code, struct TStudent *student);

int findListByPos(TLinkedList *li, int pos, struct TStudent *student);


#endif //LINKEDLIST_H
