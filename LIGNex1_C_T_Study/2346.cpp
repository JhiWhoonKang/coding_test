#include <vector>
#include <deque>
#include <iostream>

using namespace std;

struct Inform
{
	int data;
};

int main(void)
{
	int N;		// Ç³¼± °³¼ö
	cin >> N;
	deque<pair<int, int>>balloon;		// <idx, data>

	for (int i = 1; i <= N; ++i)
	{
		int data;
		cin >> data;
		balloon.push_back({ i, data });
	}

	vector<int>result;
	while (!balloon.empty())
	{
		auto cur_balloon = balloon.front();
		balloon.pop_front();
		result.push_back(cur_balloon.first);

		if (balloon.empty())
		{
			break;
		}

		int next = cur_balloon.second;
		if (cur_balloon.second > 0)
		{
			for (int i = 0; i < next - 1; ++i)
			{
				balloon.push_back(balloon.front());
				balloon.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < -next; ++i)
			{
				balloon.push_front(balloon.back());
				balloon.pop_back();
			}
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}

	return 0;
}