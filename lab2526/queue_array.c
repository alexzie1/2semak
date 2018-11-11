#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "queue_array.h"

Queue *queue_create(size_t queue_size)
{
	Queue *s = (Queue *)malloc(sizeof(Queue));
	s->data = malloc(sizeof(Item) * queue_size);
	s->ptr = 0;
	s->size = queue_size;
	return s;
}

int queue_push(Queue *s, Item value)
{
	if (queue_is_full(s)) {
		return 1;
	}
	s->data[s->ptr++] = value;
	return 0;
}

Item queue_pop(Queue *s)
{
	if (queue_is_empty(s)) {
		return 0;
	}
	return s->data[--s->ptr];
}

Item queue_top(Queue *s)
{
	if (queue_is_empty(s)) {
		return 0;
	}
	return s->data[s->ptr - 1];
}


bool queue_is_empty(Queue *s)
{
	return (s->ptr <= 0);
}

bool queue_is_full(Queue *s)
{
	return (s->ptr >= s->size);
}

void queue_destroy(Queue **s)
{
	free((*s)->data);
	free(*s);
	*s = NULL;
}

void queue_print(Queue *s) {
	Queue *tmp = queue_create(s->size);
	while (!queue_is_empty(s)) {
		printf("%d ", queue_top(s));
		queue_push(tmp, queue_pop(s));
	}

	printf("\n");

	while (!queue_is_empty(tmp)) {
		queue_push(s, queue_pop(tmp));
	}
	
	queue_destroy(&tmp);
}

void print_help() {
    printf("Menu:\n");
    printf("1  - add elem 1\n");
    printf("2  - sort_2\n");
    printf("3  - function\n");
    printf("4  - sort_1\n");
    printf("5  - add elem 2\n");
}

Queue* queue_copy(Queue *s)
{
    Queue *s_copy1 = queue_create(s->size);
    Queue *s_copy2 = queue_create(s->size);

    while (!queue_is_empty(s)) {
        queue_push(s_copy1, queue_top(s));
        queue_push(s_copy2, queue_pop(s));
    }
    while (!queue_is_empty(s_copy2)) {
        queue_push(s, queue_pop(s_copy2));
    }
    return s_copy1;
}
