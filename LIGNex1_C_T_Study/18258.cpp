#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; ++i)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int data;
			cin >> data;
			q.push(data);
		}
		else if (cmd == "pop")
		{
			cout << (q.empty() ? -1 : q.front()) << "\n";
			if (!q.empty()) q.pop();
		}
		else if (cmd == "size")
		{
			cout << q.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (cmd == "front")
		{
			cout << (q.empty() ? -1 : q.front()) << "\n";
		}
		else //"back"
		{
			cout << (q.empty() ? -1 : q.back()) << "\n";
		}
	}

	return 0;
}