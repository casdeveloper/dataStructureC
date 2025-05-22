//
// Created by Carlos Alves on 19/09/24.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct TStudent {
    int code;
    char name[30];
    float n1, n2, n3;
};

typedef struct TElement {
    TElement *prev;
    TStudent student;
    TElement *next;
};

typedef struct TElement *TList;

TList *createDublyLinkedList();

void clearList(TList *li);

int findListByPos(TList *li, int pos, struct TStudent *student);

int findListByCode(TList *li, int code, struct TStudent *student);

int insertEndList(TList *li, struct TStudent student);

int insertStarList(TList *li, struct TStudent student);

int insertOrdenedList(TList *li, struct TStudent student);

int removeList(TList *li, int code);

int removeStartList(TList *li);

int removeEndList(TList *li);

int getSizeList(TList *li);

int isEmptyList(TList *li);

void printList(TList *li);


#endif //DOUBLYLINKEDLIST_H
