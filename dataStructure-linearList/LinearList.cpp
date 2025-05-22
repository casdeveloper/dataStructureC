//
// Created by Carlos Alves on 17/09/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinearList.h" //inclui os Protótipos

TLinearList *createLinearList() {
    TLinearList *li;
    li = (TLinearList *) malloc(sizeof(struct TLinearList));
    if (li != NULL)
        li->qtt = 0;
    return li;
}

void clearLinearList(TLinearList *li) {
    free(li);
}

int findListByPos(TLinearList *li, int pos, struct TStudent *student) {
    if (li == NULL || pos <= 0 || pos > li->qtt)
        return 0;
    *student = li->students[pos - 1];
    return 1;
}

int findListByCode(TLinearList *li, int code, struct TStudent *student) {
    if (li == NULL)
        return 0;
    int i = 0;
    while (i < li->qtt && li->students[i].code != code)
        i++;
    if (i == li->qtt) //not found
        return 0;

    *student = li->students[i];
    return 1;
}

int insertEndList(TLinearList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    if (li->qtt == MAX) //Full List
        return 0;
    li->students[li->qtt] = student;
    li->qtt++;
    return 1;
}

int insertStarList(TLinearList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    if (li->qtt == MAX) //Full list
        return 0;
    int i;
    for (i = li->qtt - 1; i >= 0; i--)
        li->students[i + 1] = li->students[i];
    li->students[0] = student;
    li->qtt++;
    return 1;
}

int insertOrdenedList(TLinearList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    if (li->qtt == MAX) //3
        return 0;
    int k, i = 0;
    while (i < li->qtt && li->students[i].code < student.code)
        i++;

    for (k = li->qtt - 1; k >= i; k--)
        li->students[k + 1] = li->students[k];

    li->students[i] = student;
    li->qtt++;
    return 1;
}

int removeList(TLinearList *li, int code) {
    if (li == NULL)
        return 0;
    if (li->qtt == 0)
        return 0;
    int k, i = 0;
    while (i < li->qtt && li->students[i].code != code)
        i++;
    if (i == li->qtt) //not found
        return 0;

    for (k = i; k < li->qtt - 1; k++)
        li->students[k] = li->students[k + 1];
    li->qtt--;
    return 1;
}

int removeOptimizedList(TLinearList *li, int code) {
    if (li == NULL)
        return 0;
    if (li->qtt == 0)
        return 0;
    int i = 0;
    while (i < li->qtt && li->students[i].code != code)
        i++;
    if (i == li->qtt) //not found
        return 0;

    li->qtt--;
    li->students[i] = li->students[li->qtt];
    return 1;
}

int removeStarList(TLinearList *li) {
    if (li == NULL)
        return 0;
    if (li->qtt == 0)
        return 0;
    int k = 0;
    for (k = 0; k < li->qtt - 1; k++)
        li->students[k] = li->students[k + 1];
    li->qtt--;
    return 1;
}

int removeEndList(TLinearList *li) {
    if (li == NULL)
        return 0;
    if (li->qtt == 0)
        return 0;
    li->qtt--;
    return 1;
}

int getSizeList(TLinearList *li) {
    if (li == NULL)
        return -1;
    else
        return li->qtt;
}

int isFullList(TLinearList *li) {
    if (li == NULL)
        return -1;
    return (li->qtt == MAX);
}

int isEmpty(TLinearList *li) {
    if (li == NULL)
        return -1;
    return (li->qtt == 0);
}

void printList(TLinearList *li) {
    if (li == NULL)
        return;
    int i;
    for (i = 0; i < li->qtt; i++) {
        printf("Code: %d\n", li->students[i].code);
        printf("Name: %s\n", li->students[i].name);
        printf("Notes: %f %f %f\n", li->students[i].n1,
               li->students[i].n2,
               li->students[i].n3);
        printf("-------------------------------\n");
    }
}
