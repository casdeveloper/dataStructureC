#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    struct TStudent s[6] = {
        {2, "Andrew", 9.5, 7.8, 8.5},
        {4, "Richard", 7.5, 8.7, 6.8},
        {1, "Bryan", 9.7, 6.7, 8.4},
        {3, "Anne", 5.7, 6.1, 7.4},
        {6, "Jully", 6.7, 6.3, 9.2},
        {5, "Jhon", 5.7, 6.1, 7.4}
    };
    TLinkedList *li = createLinkedList();
    printf("Size: %d\n\n\n\n", getSizeList(li));

    int i;
    for (i = 0; i < 6; i++)
        insertOrdenedList(li, s[i]);

    printList(li);
    printf("\n\n\n\n Size: %d\n", getSizeList(li));

    for (i = 0; i < 6; i++) {
        removeEndList(li);
        printList(li);
        printf("\n Size: %d\n\n\n", getSizeList(li));
    }

    for (i = 0; i < 6; i++)
        insertOrdenedList(li, s[i]);
    printList(li);

    clearLinkedList(li);
    system("pause");
    return 0;
}
