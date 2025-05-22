//
// Created by Carlos Alves on 19/09/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

TList *createDublyLinkedList() {
    TList *li = (TList *) malloc(sizeof(TList));
    if (li != NULL)
        *li = NULL;
    return li;
}

void clearList(TList *li) {
    if (li != NULL) {
        TElement *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }
}

int findListByPos(TList *li, int pos, struct TStudent *student) {
    if (li == NULL || pos <= 0)
        return 0;
    TElement *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->next;
        i++;
    }
    if (no == NULL)
        return 0;
    else {
        *student = no->student;
        return 1;
    }
}

int findListByCode(TList *li, int code, struct TStudent *student) {
    if (li == NULL)
        return 0;
    TElement *no = *li;
    while (no != NULL && no->student.code != code) {
        no = no->next;
    }
    if (no == NULL)
        return 0;
    else {
        *student = no->student;
        return 1;
    }
}

int insertEndList(TList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    TElement *no;
    no = (TElement *) malloc(sizeof(TElement));
    if (no == NULL)
        return 0;
    no->student = student;
    no->next = NULL;
    if ((*li) == NULL) {
        //Empty List: insert at the beginning
        no->prev = NULL;
        *li = no;
    } else {
        TElement *aux;
        aux = *li;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = no;
        no->prev = aux;
    }
    return 1;
}

int insertStarList(TList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    TElement *no;
    no = (TElement *) malloc(sizeof(TElement));
    if (no == NULL)
        return 0;
    no->student = student;
    no->next = (*li);
    no->prev = NULL;
    if (*li != NULL) //Non-empty List: point to the previous
        (*li)->prev = no;
    *li = no;
    return 1;
}

int insertOrdenedList(TList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    TElement *no = (TElement *) malloc(sizeof(TElement));
    if (no == NULL)
        return 0;
    no->student = student;
    if ((*li) == NULL) {
        //Empty List: insert at the beginning
        no->next = NULL;
        no->prev = NULL;
        *li = no;
        return 1;
    } else {
        TElement *preve, *actual = *li;
        while (actual != NULL && actual->student.code < student.code) {
            preve = actual;
            actual = actual->next;
        }
        if (actual == *li) {
            //insert at the beginning
            no->prev = NULL;
            (*li)->prev = no;
            no->next = (*li);
            *li = no;
        } else {
            no->next = preve->next;
            no->prev = preve;
            preve->next = no;
            if (actual != NULL)
                actual->prev = no;
        }
        return 1;
    }
}

int removeList(TList *li, int code) {
    //Finish
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //Empty List
        return 0;
    TElement *no = *li;
    while (no != NULL && no->student.code != code) {
        no = no->next;
    }
    if (no == NULL) // not found
        return 0;

    if (no->prev == NULL) //remove de first one
        *li = no->next;
    else
        no->prev->next = no->next;

    if (no->next != NULL) //is not the last
        no->next->prev = no->prev;

    free(no);
    return 1;
}


int removeStartList(TList *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //Empty List
        return 0;

    TElement *no = *li;
    *li = no->next;
    if (no->next != NULL)
        no->next->prev = NULL;

    free(no);
    return 1;
}

int removeEndList(TList *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //Empty List
        return 0;

    TElement *no = *li;
    while (no->next != NULL)
        no = no->next;

    if (no->prev == NULL) //remove first and unique
        *li = no->next;
    else
        no->prev->next = NULL;

    free(no);
    return 1;
}

int getSizeList(TList *li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    TElement *no = *li;
    while (no != NULL) {
        cont++;
        no = no->next;
    }
    return cont;
}

int isFullList(TList *li) {
    return 0;
}

int isEmptyList(TList *li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

void printList(TList *li) {
    if (li == NULL)
        return;
    TElement *no = *li;
    while (no != NULL) {
        printf("Code: %d\n", no->student.code);
        printf("Name: %s\n", no->student.name);
        printf("Notes: %f %f %f\n", no->student.n1,
               no->student.n2,
               no->student.n3);
        printf("-------------------------------\n");

        no = no->next;
    }
}
