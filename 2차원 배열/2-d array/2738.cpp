#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	unsigned short N, M;
	cin >> N >> M;

	if (N > 100 || M > 100 || N < 1 || M < 1)
	{
		return 0;
	}

	vector<vector<short>>A(N, vector<short>(M, 0));
	vector<vector<short>>B(N, vector<short>(M, 0));
	vector<vector<int>>sum(N, vector<int>(M, 0));

	for (unsigned short i = 0; i < N; i++)
	{
		for (unsigned short j = 0; j < M; j++)
		{
			short input;
			cin >> input;

			if (input < -100 || input>100)
			{
				return 0;
			}

			A[i][j] = input;
		}
	}

	for (unsigned short i = 0; i < N; i++)
	{
		for (unsigned short j = 0; j < M; j++)
		{
			short input;
			cin >> input;

			if (input < -100 || input>100)
			{
				return 0;
			}

			B[i][j] = input;
		}
	}

	for (unsigned short i = 0; i < N; i++)
	{
		for (unsigned short j = 0; j < M; j++)
		{	
			sum[i][j] = A[i][j] + B[i][j];
			cout << sum[i][j] << " ";
		}		
		cout << endl;
	}

	return 0;
}