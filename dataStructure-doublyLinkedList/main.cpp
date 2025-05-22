#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main() {
    struct TStudent al, a[4] = {
        {2, "Andrew", 9.5, 7.8, 8.5},
        {4, "Ricahrd", 7.5, 8.7, 6.8},
        {1, "Bryan", 9.7, 6.7, 8.4},
        {3, "Anne", 5.7, 6.1, 7.4}
    };
    TList *li = createDublyLinkedList();
    printf("Size: %d\n\n\n\n", getSizeList(li));

    int i;
    for (i = 0; i < 4; i++)
        insertOrdenedList(li, a[i]);

    printList(li);
    printf("\n\n\n\n Size: %d\n", getSizeList(li));


    //remove list(li,3);
    for (i = 0; i < 4; i++) {
        removeEndList(li);
        printList(li);
        printf("\nSize: %d\n\n\n\n", getSizeList(li));
    }

    for (i = 0; i < 4; i++)
        insertOrdenedList(li, a[i]);

    printList(li);
    clearList(li);
    system("pause");
    return 0;
}
