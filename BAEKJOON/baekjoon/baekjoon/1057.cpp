#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;//참가자의 수
	int A, B;//김지민, 임한수 순
	cin >> N >> A >> B;
	if (N < 1 || N>100000 || A<1 || B<1 || A>N || B>N || A==B)
	{
		return 0;
	}
	int cnt = 0;
	while (A != B)
	{
		A = (A + 1) / 2;
		B = (B + 1) / 2;

		cnt++;
	}

	cout << cnt;


	return 0;
}