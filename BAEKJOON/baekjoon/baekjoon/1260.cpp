#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	int left;
	int right;
};

vector<vector<int>>tree;
vector<bool>dfs_visited;
vector<bool>bfs_visited;

void dfs(int node)
{
	dfs_visited[node] = true;
	cout << node << " ";
	for (int neighbor : tree[node])
	{
		if (!dfs_visited[neighbor])
		{
			dfs(neighbor);
		}
	}
}

void bfs(int node)
{
	queue<int>q;
	q.push(node);
	bfs_visited[node] = true;
	
	while (!q.empty())
	{
		int next = q.front();
		cout << next << " ";
		q.pop();

		for (int neighbor : tree[next])
		{
			if (!bfs_visited[neighbor])
			{
				bfs_visited[neighbor] = true;
				q.push(neighbor);
			}
		}
		
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M, V;
	cin >> N >> M >> V;
	
	tree.resize(N + 1);
	dfs_visited.resize(N + 1, false);
	bfs_visited.resize(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}
	

	dfs(V);
	cout << "\n";
	bfs(V);

	return 0;
}