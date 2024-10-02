#include<iostream>
#include<vector>
using namespace std;

int main(void)
{	
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X;
	cin >> N >> X;
	

	if (N < 1 || N>10000 || X < 1 || X>10000)
	{
		return 0;
	}

	vector <int>storage(N);
	
	for (int a = 0; a < N; a++)
	{
		cin >> storage[a];
	}

	vector<int> result;
	for (int a = 0; a < N; a++)
	{
		if (storage[a] < X)
		{
			result.push_back(storage[a]);
		}
	}

	for (int a = 0; a < result.size(); a++)
	{
		cout << result[a];
		if (a < result.size() - 1)
		{
			cout << " ";
		}
	}

	return 0;
}