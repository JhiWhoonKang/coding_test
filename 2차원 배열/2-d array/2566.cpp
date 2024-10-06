#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector<vector<unsigned short>>arr(9, vector<unsigned short>(9, 0));

	short max_value = -1;
	unsigned short row = 0, column = 0;

	for (unsigned short i = 0; i < 9; i++)
	{
		for (unsigned short j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= 100 || arr[i][j] < 0)
			{
				return 0;
			}

			if (max_value < arr[i][j])
			{
				max_value = arr[i][j];
				row = i + 1;
				column = j + 1;
			}
		}
	}

	cout << max_value << endl;
	cout << row << " " << column;

	return 0;
}