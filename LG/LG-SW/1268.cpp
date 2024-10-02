#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	const unsigned short grades = 5;
	unsigned short total_students_num;

	cin >> total_students_num;

	vector<vector <unsigned short>>inform(total_students_num, vector<unsigned short>(grades));

	if (total_students_num < 3 || total_students_num>1000)
	{
		return 0;
	}

	for (int a = 0; a < total_students_num; a++)
	{
		for (int b = 0; b < grades; b++)
		{
			cin >> inform[a][b];
			if (inform[a][b] > 9 || inform[a][b] < 1)
			{
				return 0;
			}
		}		
	}
	
	vector<unsigned short>compare(total_students_num, 0);

	for (int i = 0; i < total_students_num; i++)
	{
		for (int j = i + 1; j < total_students_num; j++)
		{
			for (int k = 0; k < grades; k++)
			{
				if (inform[i][k] == inform[j][k])
				{
					compare[i]++;
					compare[j]++;
					break;
				}
			}			
		}
	}

	/*int max_count = 0;
	int leader = 0;
	for (int i = 0; i < total_students_num; i++) {
		if (compare[i] > max_count) {
			max_count = compare[i];
			leader = i;
		}
	}

	cout << leader + 1 << endl;*/

	// 

	/*cout << "\n";

	for (int a = 0; a < total_students_num; a++)
	{
		cout << compare[a] << "\n";
	}*/

	//cout << "\n";

	auto max_value = max_element(compare.begin(), compare.end());
	//cout << *max_value;

	//cout << "\n";
	int index = distance(compare.begin(), max_value);
	cout << index + 1;

	

	return 0;
}