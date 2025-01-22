//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int main(void)
//{
//	int N;
//	int arr[10] = { 0 };
//	int result = 0;
//	(void)scanf("%d", &N);
//	for (int i = 1;i <= N;++i)
//	{
//		arr[i] = i;
//	}
//
//	int cnt = 1;
//	while (cnt != N)
//	{
//		for (int i = 1;i <= N;++i)
//		{
//			if (arr[i] != 0)
//			{
//				++cnt;				
//				arr[i] = 0;
//				result = arr[i + 1];
//			}
//		}
//	}
//
//	printf("%d", result);
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int N;
    (void)scanf("%d", &N);

    // heap 영역 메모리 할당
    // stack 영역으로 하면 stack overflow 발생
    int *arr = (int*)malloc(sizeof(int) * (N * 2));
    int front = 1, rear = N + 1;

    // 배열에 차례대로 집어넣기, 1번 idx 시작
    // rear: 마지막 index (=N)
    for (int i = 1; i <= N; ++i) 
    {
        arr[i] = i;
    }

    /*
    * 구현 알고리즘: 맨 뒤 idx를 알고, 맨 뒤 idx를 알면 맨 앞 idx(지워진 후의 값)를 맨 뒤 idx 값으로 변경
    * arr[맨 뒤 idx] = arr[맨 앞 idx]
    */
    while (rear - front > 1) 
    {
        ++front;
        arr[rear++] = arr[front++];
    }

    printf("%d\n", arr[front]);

    free(arr);

    return 0;
}
