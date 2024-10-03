#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	long long sum = 0;

	cin >> N;
	if (N < 1 || N>2000000)
	{
		return 0;
	}

	for (long long q = 1; q * (N + 1) < 2 * N; q++)
	{

	}

	/*
	x/n=q
	x=q*n

	x%n=r

	q=r
	x/n=x%n
	
	x=q*n+q
	*/

	return 0;
}