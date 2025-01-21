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
		circular[i] = i;
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
	for (; delete_cnt < N;)
	{
		for (; temp_idx < K;)
		{
			crt_pos = crt_pos % N + 1;			
			if (circular[crt_pos] != 0)
			{
				++temp_idx;
			}
		}
		printf("%d", circular[crt_pos]);
		circular[crt_pos] = 0;
		++delete_cnt;
		if (delete_cnt < N)
		{
			printf(", ");
		}
		temp_idx = 0;
	}
	printf(">");

	return 0;
}