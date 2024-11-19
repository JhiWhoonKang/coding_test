#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<int>& Visited)
{
	Visited[node]++;
	for (int next : graph[node])
	{
		if (Visited[next] == 0)
		{
			DFS(next, graph, Visited);
		}
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, R;
	cin >> N >> M >> R;
	if (N < 5 || N>100000 || M < 1 || M>200000 || R<1 || R>N)
	{
		return 0;
	}
	
	vector<vector<int>>graph(N + 1);
	vector<int> Visited(N+1, 0);

	for (int i = 0; i <	M; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u<1 || u>N || v<1 || v>N || u == v)
		{
			return 0;
		}
		graph[u].push_back(v);
		graph[v].push_back(u);		
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(R, graph, Visited);

	for (int i = 1; i <= N; i++)
	{
		cout << Visited[i] << "\n";
	}

	return 0;
}