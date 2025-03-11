#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>>conference(N);	// <start_time, end_time>
	for (int i = 0;i < N;++i)
	{
		cin >> conference[i].first >> conference[i].second;
	}


	sort(conference.rbegin(), conference.rend());

	int	classNum = 0;
	for (int i = 0;i < N;++i)
	{

	}

	return 0;
}