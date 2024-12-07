#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>network;
vector<bool>visited;

int bfs(int start)
{	
	queue<int>q;
	q.push(start);
	visited[start] = true;
	int infected_count = 0;
	
	while (!q.empty())
	{
		int current = q.front();	
		q.pop();

		for (int neighbor : network[current])
		{
			if (!visited[neighbor])
			{
				visited[neighbor] = true;
				q.push(neighbor);
				infected_count++;
			}
		}
	}

	return infected_count;
}


int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int total_num;
	cin >> total_num;

	network.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < total_num; i++)
	{
		int A, B;
		cin >> A >> B;

		network[A].push_back(B);
		network[B].push_back(A);
	}

	int result = bfs(1);
	cout << result << endl;

	return 0;
}
