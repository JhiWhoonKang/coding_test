#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;		// 숫자 1 ~ N
				// 초기 맨 위 : 1, 맨 아래 : N
	// 단계 i
	// (i = 1) 단계: 맨 및 2^K개의 카드를 더미 맨 위로 올림
	// 카드 섞기 단계: K + 1 단계
	// 이후 i = 2 ~ i = (K + 1)
		// 직전에 맨 위로 올린 카드 중 밑에서 2^(K-i+1)개의 카드를 맨 위로 올림

	return 0;
}