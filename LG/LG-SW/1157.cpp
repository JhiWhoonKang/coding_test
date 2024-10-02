#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	string alpha;
	cin >> alpha;

	if (alpha.size() > 1000000)
	{
		return 0;
	}

	transform(alpha.begin(), alpha.end(), alpha.begin(), ::toupper);

	int test[26] = { 0, };

	for (char c: alpha)
	{
		test[c - 'A']++;
	}

	int max_cnt = 0;
	char max_alpha = 'A';
	bool duplicate = false;

	for (int i = 0; i < 26; i++)
	{
		if (test[i] > max_cnt)
		{
			max_cnt = test[i];
			max_alpha = 'A' + i;
			duplicate = false;
		}

		else if (max_cnt == test[i])
		{
			duplicate = true;
		}
	}

	if (duplicate)
	{
		cout << "?";
	}

	else
	{
		cout << max_alpha;
	}

	return 0;
}