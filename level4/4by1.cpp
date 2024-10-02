#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	bool condition_flag = false;

	cin >> N;

	vector<int>numbers(N);

	if (N < 1 || N > 100) {
		cout << 0 << endl;
		return 0;
	}


	for (int a = 0; a < N; a++)
	{
		cin >> numbers[a];
	}

	int searching;
	int counted = 0;

	cin >> searching;

	for (int a = 0; a < N; a++)
	{
		if (numbers[a] == searching)
		{
			counted++;
		}
	}

	cout << counted << endl;


	return 0;
}