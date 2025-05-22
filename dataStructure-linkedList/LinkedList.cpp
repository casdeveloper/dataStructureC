//
// Created by Carlos Alves on 17/09/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


TLinkedList *createLinkedList() {
    TLinkedList *li = (TLinkedList *) malloc(sizeof(TLinkedList));
    if (li != NULL)
        *li = NULL;
    return li;
}

void clearLinkedList(TLinkedList *li) {
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

int findListByPos(TLinkedList *li, int pos, struct TStudent *student) {
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
        *student = no->students;
        return 1;
    }
}

int findListByCode(TLinkedList *li, int code, struct TStudent *student) {
    if (li == NULL)
        return 0;
    TElement *no = *li;
    while (no != NULL && no->students.code != code) {
        no = no->next;
    }
    if (no == NULL)
        return 0;
    else {
        *student = no->students;
        return 1;
    }
}

int insertEndList(TLinkedList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    TElement *no;
    no = (TElement *) malloc(sizeof(TElement));
    if (no == NULL)
        return 0;
    no->students = student;
    no->next = NULL;
    if ((*li) == NULL) {
        //Empty List: insert at the beginning
        *li = no;
    } else {
        TElement *aux;
        aux = *li;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = no;
    }
    return 1;
}

int insertStartList(TLinkedList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    TElement *no;
    no = (TElement *) malloc(sizeof(TElement));
    if (no == NULL)
        return 0;
    no->students = student;
    no->next = (*li);
    *li = no;
    return 1;
}

int insertOrdenedList(TLinkedList *li, struct TStudent student) {
    if (li == NULL)
        return 0;
    TElement *no = (TElement *) malloc(sizeof(TElement));
    if (no == NULL)
        return 0;
    no->students = student;
    if ((*li) == NULL) {
        //Empty List: insert at the beginning
        no->next = NULL;
        *li = no;
        return 1;
    } else {
        TElement *ant, *atual = *li;
        while (atual != NULL && atual->students.code < student.code) {
            ant = atual;
            atual = atual->next;
        }
        if (atual == *li) {
            //insert at the beginning
            no->next = (*li);
            *li = no;
        } else {
            no->next = atual;
            ant->next = no;
        }
        return 1;
    }
}

int removeList(TLinkedList *li, int code) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //Empty List
        return 0;
    TElement *ant, *no = *li;
    while (no != NULL && no->students.code != code) {
        ant = no;
        no = no->next;
    }
    if (no == NULL) //not found
        return 0;

    if (no == *li) //remove the first one?
        *li = no->next;
    else
        ant->next = no->next;
    free(no);
    return 1;
}

int removeStartList(TLinkedList *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //Empty List
        return 0;

    TElement *no = *li;
    *li = no->next;
    free(no);
    return 1;
}

int removeEndList(TLinkedList *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //Empty List
        return 0;

    TElement *ant, *no = *li;
    while (no->next != NULL) {
        ant = no;
        no = no->next;
    }

    if (no == (*li)) //remove the first one?
        *li = no->next;
    else
        ant->next = no->next;
    free(no);
    return 1;
}

int getSizeList(TLinkedList *li) {
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

int isFullList(TLinkedList *li) {
    return 0;
}

int isEmptyList(TLinkedList *li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

void printList(TLinkedList *li) {
    if (li == NULL)
        return;
    TElement *no = *li;
    while (no != NULL) {
        printf("Code: %d\n", no->students.code);
        printf("Name: %s\n", no->students.name);
        printf("Notes: %f %f %f\n", no->students.n1,
               no->students.n2,
               no->students.n3);
        printf("-------------------------------\n");

        no = no->next;
    }
}
