#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	if (N < 1 || N>100 || M < 1 || M>100)
	{
		return 0;
	}

	vector<int> bucket(N, 0);

	for (int a = 0; a < N; a++)
	{
		bucket[a] = a + 1;
	}

	for (int a = 0; a < M; a++)
	{
		int i, j;
		cin >> i >> j;

		if (i<1 || i>N || j<1 || j>N)
		{
			return 0;
		}

		reverse(bucket.begin() + (i - 1), bucket.begin() + j);
	}

	for (int a = 0; a < N; a++)
	{
		cout << bucket[a] << " ";
	}

	return 0;
}