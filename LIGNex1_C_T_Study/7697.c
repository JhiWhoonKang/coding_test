#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
 
typedef struct _Pair
{
	int position;
	int size;
} Pair;

typedef struct _Queue
{
	int front;
	int rear;
	int data[];
}Queue;

void createQueue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

void pushQueue(Queue* q, int data)
{
	q->data[q->rear++] = data;
}

int popQueue(Queue* q)
{
	return q->data[q->front++];
}

int main(void)
{
	int N;
	(void)scanf("%d", &N);

	int* Ary = (int*)malloc(sizeof(int) * (N + 1));
	createQueue();
	for (int i = 0;i < 5;++i)
	{
		(void)scanf("%d", Ary + i);
	}



	return 0;
}
