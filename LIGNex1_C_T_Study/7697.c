#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
 
// 미생물 위치, 크기 정보
typedef struct
{
	int position;
	int size;
} Pair;

typedef struct
{
	Pair* data;
	int front;
	int rear;
	int capacity;
}Queue;

Queue* createQueue(int capacity)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (Pair*)malloc(sizeof(Pair) * capacity);
	q->front = 0;
	q->rear = 0;
	q->capacity = capacity;
	return q;
}

void pushQueue(Queue* q, Pair data)
{
	q->data[q->rear++] = data;
}

Pair popQueue(Queue* q)
{
	return q->data[q->front++];
}



int main(void)
{
	int N;
	(void)scanf("%d", &N);

	// queue에 데이터 넣기 { index, size } 순
	Queue* q = createQueue(N);	
	for (int i = 0; i < N; ++i)
	{
		int size;
		(void)scanf("%d", &size);
		Pair pair = { i, size };
		pushQueue(q, pair);
	}

	while()

	return 0;
}
