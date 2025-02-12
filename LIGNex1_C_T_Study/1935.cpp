#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	string input;
	cin >> input;

	vector<int>data(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> data[i];
	}

	for (char ch : input)
	{
		if (isalpha(ch))
		{
			
		}
	}

	return 0;
}