//
// Created by Carlos Alves on 17/09/24.
//
#include <stdio.h>
#include <stdlib.h>

#include "LinearList.h"

int main() {
    struct TStudent s[6] = {
        {2, "Andrew", 9.5, 7.8, 8.5},
        {4, "Richard", 7.5, 8.7, 6.8},
        {1, "Bryan", 9.7, 6.7, 8.4},
        {3, "Anne", 5.7, 6.1, 7.4},
        {6, "Jully", 6.7, 6.3, 9.2},
        {5, "Jhon", 5.7, 6.1, 7.4}
    };
    TLinearList *li = createLinearList();
    int i;
    for (i = 0; i < 4; i++)
        insertOrdenedList(li, s[i]);

    printList(li);
    printf("\n\n\n\n");


    TStudent *stu = (TStudent *) malloc(sizeof(TStudent)); // using pointer to vector
    TStudent stu1 = TStudent(); // using function by reference

    if (findListByCode(li, 3, stu) > 0) {
        printf("Student has code %s\n", stu->name);
    }

    if (findListByCode(li, 3, &stu1) > 0) {
        printf("Student has code %s\n", stu1.name);
    }

    for (i = 0; i < 5; i++) {
        if (!removeOptimizedList(li, i))
            printf("Erro\n");

        printList(li);
        printf("\n\n\n\n");
    }

    clearLinearList(li);
    system("pause");
    return 0;
}
