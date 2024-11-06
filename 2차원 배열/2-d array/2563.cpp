#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	unsigned short num;
	cin >> num;
	if (num > 100)
	{
		return 0;
	}
	
	unsigned int x, y;
	vector<vector<unsigned short>> coordinates(num, vector<unsigned short>(2, 0));
	for (int i = 0; i < num; i++)
	{
		/*for (int j = 0; j < 2; j++)
		{
			cin >> coordinates[i][j];
			if (coordinates[i][j] + 10 > 100)
			{
				return 0;
			}


		}*/

		cin >> x >> y;
		if (x + 10 > 100 || y + 100)
		{
			return 0;
		}

		for (unsigned short _x = 0; _x < x; _x++)
		{
			for (unsigned short _y = 0; _y < y; _y++)
			{
				coordinates[_x][_y] = 1;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << coordinates[i][j];
		}
	}

	return 0;
}