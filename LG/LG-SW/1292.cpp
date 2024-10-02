#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	unsigned short A, B;

	cin >> A >> B;
	if (A < 1 || B < 1 || A>1000 || B>1000)
	{
		return 0;
	}

	vector<unsigned short> sequence;

	for (int i = 1; i <= B; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sequence.push_back(i);
			if (sequence.size() == B)
			{
				break;
			}
		}
		if (sequence.size() == B)
		{
			break;
		}		
	}

	int total_sum = 0;

	for (int i = A; i <= B; i++)
	{
		total_sum += sequence[i - 1];
	}

	cout << total_sum;

	return 0;
}