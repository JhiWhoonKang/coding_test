#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int dest;
	long long cost;
};

vector<vector<Node>>tree;

pair<int, long long> bfs(int node, int N)
{
	vector<long long>distance(N + 1, -1);
	queue<int>q;
	q.push(node);
	distance[node] = 0;
	
	int farthest_node = node;
	long long max_distance = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (auto& edge : tree[current])
		{
			if (distance[edge.dest] == -1)
			{				
				distance[edge.dest] = distance[current] + edge.cost;
				q.push(edge.dest);
				if (distance[edge.dest] > max_distance)
				{
					max_distance = distance[edge.dest];
					farthest_node = edge.dest;
				}
			}
		}
	}

	return { farthest_node, max_distance };
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	if (N < 1 || N>5000)
	{
		return 0;
	}

	tree.resize(N + 1);

	for (int i = 1; i < N; i++)
	{
		int A, B;
		long long C;
		cin >> A >> B >> C;
		if (A<1 || B<1 || A>N || B>N || C < 1 || C>1000000000)
		{
			return 0;
		}
		tree[A].push_back({ B, C });
		tree[B].push_back({ A, C });
	}

	auto result = bfs(1, N);
	cout << result.second << '\0';

	return 0;
}