#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

// 스택 idx를 전역으로 사용하여 각 함수에서 조절된 idx 값을 통해 함수 동작
int Index = -1;
int stack[MAX];

void push(int data);
int pop();
int size();
int empty();
int top();

int main(void)
{
	int N;
	(void)scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		//명령어가 최대 5글자이기 때문에 넉넉하게 10 사이즈 cmd 배열 생성 후 입력
		char _cmd_[10] = { ' ' };
		(void)scanf("%s", _cmd_);

		// strcmp 활용 명령어 비교 
		if (strcmp(_cmd_, "push") == 0)
		{
			int _data_;
			(void)scanf("%d", &_data_);
			push(_data_);
		}
		else if (strcmp(_cmd_, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(_cmd_, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(_cmd_, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(_cmd_, "top") == 0)
		{
			printf("%d\n", top());
		}
	}

	return 0;
}

void push(int data)
{
	if (Index < MAX - 1)
	{
		stack[++Index] = data;
	}
	return;
}

int  pop()
{
	if (Index == -1)
	{
		return -1;
	}
	return stack[Index--];
}

int size()
{
	return Index + 1; // idx -1부터 시작했기에 + 1
}

int empty()
{
	if (Index == -1)
	{
		return 1;
	}
	return 0;
}

int top()
{
	if (Index == -1)
	{
		return -1;
	}
	return stack[Index];
}