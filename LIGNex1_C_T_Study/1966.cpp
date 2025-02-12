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
		int N;		//N: ������ ����
		int M;		//M: �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Queue���� �� ��°�� ���� �ִ����� ��Ÿ���� ����
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