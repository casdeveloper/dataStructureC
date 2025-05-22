//
// Created by Carlos Alves on 17/09/24.
//

#ifndef LINEARLIST_H
#define LINEARLIST_H

#define MAX 100

typedef struct TStudent {
    int code;
    char name[30];
    float n1, n2, n3;
};

typedef struct TLinearList {
    int qtt;
    TStudent students[MAX];
};

TLinearList *createLinearList();

void clearLinearList(TLinearList *li);

int findListByPos(TLinearList *li, int pos, struct TStudent *student);

int findListByCode(TLinearList *li, int code, struct TStudent *student);

int insertEndList(TLinearList *li, struct TStudent student);

int insertStarList(TLinearList *li, struct TStudent student);

int insertOrdenedList(TLinearList *li, struct TStudent student);

int removeList(TLinearList *li, int code);

int removeStarList(TLinearList *li);

int removeEndList(TLinearList *li);

int getSizeList(TLinearList *li);

int isFullList(TLinearList *li);

int isEmpty(TLinearList *li);

void printList(TLinearList *li);

int removeOptimizedList(TLinearList *li, int code);


#endif //LINEARLIST_H
