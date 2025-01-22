#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, K;
	(void)scanf("%d %d", &N, &K);

	int circular[5001];
	int result[5001];
	for (int i = 1; i <= N; ++i)
	{
		circular[i] = i; //1번부터 N번까지 각 idx에 값 할당
	}
	
	printf("<");
	int delete_cnt = 0;
	/*for (int i = K; delete_cnt != N; i+=K, ++delete_cnt)
	{		
		if (i + K > N)
		{
			i = K - N - i;
		}
		if (circular[i] == 0)
		{
			continue;
		}
		printf("%d", circular[i]);
		circular[i] = 0;
		if (delete_cnt + 1 == N)
		{
			printf(",");
		}
	}*/

	int crt_pos = 0;
	int temp_idx = 0;
	for (; delete_cnt < N;) //종료 조건: 제거 될 때 마다 delete_cnt 값 증가(== N회 반복)
	{
		for (; temp_idx < K;) // K번째 사람 제거 위한 for문
		{
			crt_pos = crt_pos % N + 1; //1번 idx 부터 시작했기에 +1
			if (circular[crt_pos] != 0) //제거된 경우: 0, 제거되지 않은 경우: 0 이외의 값
			{
				++temp_idx; //제거되지 않은 경우만 인식해서 idx 증가
			}
		}
		printf("%d", circular[crt_pos]); //K번째 사람 출력
		circular[crt_pos] = 0; //K번째 사람 제거
		++delete_cnt; //delete_cnt 증가
		if (delete_cnt < N) //더 반복해야 하는 경우 "." 출력
		{
			printf(", ");
		}
		temp_idx = 0; // 다시 K회 반복하시 위해 temp_idx 초기화
	}
	printf(">");

	return 0;
}