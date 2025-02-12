#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int loop;
	cin >> loop;
	

	while (loop--)
	{
		int N;		//N: 문서의 개수
		int M;		//M: 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여 있는지를 나타내는 정수
		cin >> N >> M;

		vector<int>search;
		queue<pair<int, int>>q;		//<idx, priority>
		for (int i = 0; i < N; ++i)
		{
			int prior;
			cin >> prior;
			q.push({ i, prior });
			search.push_back(prior);
		}

		sort(search.rbegin(), search.rend());

		int idx = 0;
		while (!q.empty())
		{
			int cur_idx = q.front().first;
			int cur_prior = q.front().second;
			q.pop();

			if (cur_prior == search[idx])
			{
				++idx;
				if (cur_idx == M)
				{
					cout << idx << "\n";
					break;
				}				
			}
			else
			{
				q.push({ cur_idx, cur_prior });
			}
		}
	}

	return 0;
}