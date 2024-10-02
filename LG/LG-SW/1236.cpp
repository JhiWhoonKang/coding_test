#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	unsigned short N, M;

	cin >> N >> M;

	if (N > 50 || M > 50)
	{
		return 0;
	}

	vector<vector<char>> castle(N, vector<char>(M));

	vector<bool> raw(N, false);
	vector<bool> column(M, false);

	unsigned short raw_cnt = 0;
	unsigned short column_cnt = 0;
	unsigned short 
		= 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> castle[i][j]; //.: ºó°£, X: °æºñ¿ø ¤·¤·
			if (castle[i][j] == 'X')
			{
				raw[i] = true;
				column[j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (raw[i] == false)
		{
			raw_cnt++;
		}
	}

	for (int j = 0; j < M; j++)
	{
		if (column[j] == false)
		{
			column_cnt++;
		}
	}

	cout << max(raw_cnt, column_cnt) << endl;
	
	return 0;
}