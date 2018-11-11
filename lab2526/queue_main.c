#include <stdio.h>
#include <stdbool.h>

#include "queue_array.h"
#include "sort.h"


int main()
{
    int size1, size2;
    printf("Insert size of memory 1: ");
    scanf("%d", &size1);
    printf("Insert size of memory 2: ");
    scanf("%d", &size2);
    Queue *s1 = queue_create(size1);
    Queue *s2 = queue_create(size2);
    int massiv[size1];
    int cmd;
    int a = 0;
    int *i;
    i = &a;
    print_help();

    int input;
    int work = 1;

    while (work && scanf("%d", &cmd) == 1) {
        switch(cmd) {
            case 1:
                scanf("%d", &input);
                queue_push(s1, input);
                break;
            case 2:
                queue_sort2(s2);
                queue_print(s2);
                break;
            case 3:
                unctionm(s1, s2);
                break;
            case 4:
                create_massiv(s1, massiv, i);
                quickSort(massiv, 0, a - 1);
                queue_form_massiv(massiv, s1, a);
                break;
            case 5:
                scanf("%d", &input);
                queue_push(s2, input);
                break;
        }
    }
    queue_destroy(&s1);
    queue_destroy(&s2);
}
