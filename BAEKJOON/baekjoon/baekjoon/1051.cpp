#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;
	if (N > 50 || M > 50 || N < 1 || M < 1)
	{
		return 0;
	}
	string input;
	vector<vector<int>> RECT(N, vector<int>(M, 0));
	
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			RECT[i][j] = input[j] - '0';
		}
	}

	int max_size = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 1; i + k < N && j + k < M; k++)
			{
				if (RECT[i][j] == RECT[i][j + k] &&
					RECT[i][j] == RECT[i + k][j] &&
					RECT[i][j] == RECT[i + k][j + k])
				{				
					max_size = max(max_size, (k + 1) * (k + 1));
				}
			}
		}
	}

	cout << max_size << endl;

	return 0;
}