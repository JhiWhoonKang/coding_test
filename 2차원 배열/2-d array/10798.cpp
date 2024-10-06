#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector<string> words(5);
	unsigned short max_len = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> words[i];
		if (words[i].length() > 15)
		{
			return 0;
		}

		if (max_len < words[i].length())
		{
			max_len = words[i].length();
		}
	}

	for (int j = 0; j < max_len; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (j < words[i].length())
			{
				cout << words[i][j];
			}
		}		
	}

	return 0;
}