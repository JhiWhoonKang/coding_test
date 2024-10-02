#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<int> bucket(N, 0);

	for (int a = 0; a < N; a++)
	{
		bucket[a] = a + 1;
	}

	for (int a = 0; a < M; a++)
	{
		int i, j, temp;
		cin >> i >> j;
		/*i -= 1;
		j -= 1;
		temp = bucket[j];
		bucket[j] = bucket[i];		
		bucket[i] = temp;		*/

		swap(bucket[i - 1], bucket[j - 1]);
	}

	for (int a = 0; a < N; a++)
	{
		cout << bucket[a] << " ";
	}
}