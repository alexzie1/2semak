#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdbool.h>
#include "queue_array.h"

void quickSort(int *numbers, int left, int right);
void queue_sort2(Queue *s);
void queue_form_massiv(int *massiv, Queue *s, int a);
int* create_massiv(Queue *s, int *massiv, int *i_old);
void unctionm(Queue *s1, Queue *s2);

#endif
