#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;		// 회의 개수
	cin >> N;

	vector<pair<int, int>>conference(N);	// <startTime, endTime>
	for (int i = 0; i < N; ++i)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		conference[i] = { startTime, endTime };
	}

	return 0;
}