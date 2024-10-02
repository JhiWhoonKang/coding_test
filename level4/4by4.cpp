#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL); cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputs[9];

	for (int a = 0; a < 9; a++)
	{
		cin >> inputs[a];
		if (inputs[a] >= 100 || inputs[a] == 0)
		{
			return 0;
		}
	}

	int max = inputs[0];
	int v = 1;
	int a = 0;
	for (a = 0; a < 9; a++)
	{
		if (max < inputs[a])
		{
			max = inputs[a];
			v = a + 1;
		}

	}

	cout << max << '\n' << v;

	return 0;
}