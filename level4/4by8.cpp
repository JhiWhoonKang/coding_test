#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	set<int> remainders;
	int num;

	for (int a = 0; a < 10; a++)
	{
		cin >> num;
		remainders.insert(num % 42);
	}

	cout << remainders.size();

	return 0;
}