#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int max, min;
	vector<int>inputs(N);

	if (N < 1 || N>1000000)
	{
		return 0;
	}

	for (int a = 0; a < N; a++)
	{
		cin >> inputs[a];
	}

	max = min = inputs[0];

	for (int a = 0; a < N; a++)
	{
		if (inputs[a] < -1000000 || inputs[a]>1000000)
		{
			return 0;
		}

		if (max < inputs[a])
		{
			max = inputs[a];
		}

		if (min > inputs[a])
		{
			min = inputs[a];
		}		
	}

	cout << min << " " << max;

	return 0;
}