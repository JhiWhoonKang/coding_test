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

    // heap ���� �޸� �Ҵ�
    // stack �������� �ϸ� stack overflow �߻�
    int *arr = (int*)malloc(sizeof(int) * (N * 2));
    int front = 1, rear = N + 1;

    // �迭�� ���ʴ�� ����ֱ�, 1�� idx ����
    // rear: ������ index (=N)
    for (int i = 1; i <= N; ++i) 
    {
        arr[i] = i;
    }

    /*
    * ���� �˰���: �� �� idx�� �˰�, �� �� idx�� �˸� �� �� idx(������ ���� ��)�� �� �� idx ������ ����
    * arr[�� �� idx] = arr[�� �� idx]
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
