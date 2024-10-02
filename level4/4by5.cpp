#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;//N: 바구니 개수, M: 공 번호
	cin >> N >> M;
	vector<int> bucket(N, 0);
	
	if ((N < 1 || N>100) || (M < 1 || M>100))
	{
		return 0;
	}

	for (int a = 0; a < M; a++)
	{
		int i, j, k;
		cin >> i >> j >> k;
		
		if (i < 1 || i > N || j < 1 || j > N || k < 1 || k > N)
		{
			return 0;
		}

		for (int x = i-1; x < j; x++)
		{
			bucket[x] = k;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << bucket[i] << " ";
	}
}