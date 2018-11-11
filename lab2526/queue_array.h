#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct {
	int ptr;
	int size;
	Item *data;
} Queue;

Queue *queue_create(size_t queue_size);
int queue_push(Queue *s, Item value);
Item queue_pop(Queue *s);
Item queue_top(Queue *s);
bool queue_is_empty(Queue *s);
bool queue_is_full(Queue *s);
void queue_destroy(Queue **s);
void queue_print(Queue *s);
void print_help();
Queue* queue_copy(Queue *s);

#endif