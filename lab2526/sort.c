#include "sort.h"
#include "queue_array.h"
#include <stdio.h>

void queue_sort2(Queue *s) {
    int x = queue_pop(s);
    Queue *s1 = queue_create(s->size);
    Queue *s2 = queue_create(s->size);
    Queue *tmp = queue_create(s->size);
    int y;
    while (!queue_is_empty(s)) {
        y = queue_pop(s);
        if (y > x) {
            queue_push(s2, y);
        } else {
            queue_push(s1, y);
        }
    }
    if (s1->ptr > 1) {
        queue_sort2(s1);
    }
    if (s2->ptr > 1) {
        queue_sort2(s2);
    }
    while (!queue_is_empty(s1)) {
        queue_push(tmp, queue_pop(s1));
    }
    queue_push(tmp, x);
    while (!queue_is_empty(s2)) {
        queue_push(tmp, queue_pop(s2));
    }
    while (!queue_is_empty(tmp)) {
        queue_push(s, queue_pop(tmp));
    }
    queue_destroy(&s1);
    queue_destroy(&s2);
    queue_destroy(&tmp);
}







void quickSort(int *numbers, int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) // пока границы не сомкнутся
    {
    while ((numbers[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}

void queue_form_massiv(int *massiv, Queue *s, int a) 
{
    Queue *s_copy = queue_create(s->size);
    for (int i = a - 1; i >= 0; i--) {
        queue_push(s_copy, massiv[i]);
    }
    queue_print(s_copy);
    queue_destroy(&s_copy);
} 

int* create_massiv(Queue *s, int *massiv, int *i_old) 
{
    Queue *tmp = queue_create(s->size);
    int i = 0;
    while (!queue_is_empty(s)) {
        massiv[i] = queue_top(s);
        queue_push(tmp, queue_pop(s));
        i++;
    }
    
    *i_old = i;
    
    while (!queue_is_empty(tmp)) {
        queue_push(s, queue_pop(tmp));
    }
    queue_destroy(&tmp);
    return massiv;
}


void unctionm(Queue *s1, Queue *s2) 
{
    int a = 0;
    int b;
    int *i;
    i = &a;
    Queue *tmp = queue_create((s1->size) + (s2->size));
    Queue *s1_copy = queue_copy(s1);
    b = sizeof(tmp);
    int massiv[b];
    Queue *s2_copy = queue_copy(s2);
    
    while (!queue_is_empty(s1_copy)) {
        queue_push(tmp, queue_pop(s1_copy)); 
    }
    while (!queue_is_empty(s2_copy)) {
        queue_push(tmp, queue_pop(s2_copy));
    }
    create_massiv(tmp, massiv, i);
    quickSort(massiv, 0, a - 1);
    queue_form_massiv(massiv, tmp, a);


    
    queue_destroy(&tmp);
}
