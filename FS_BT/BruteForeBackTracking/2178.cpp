#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>>map;
vector<vector<bool>>visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x, y });
	int path = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && map[nx][ny] == 1)
			{
				q.push({ nx, ny });
				++path;
				visited[nx][ny] = true;
			}
		}		
	}
	return path;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	map.resize(N, vector<int>(M, -1));
	visited.resize(N, vector<bool>(M, false));

	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < M;++j)
		{
			cin >> map[i][j];
		}
	}

	int minPath = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				minPath = min(bfs(i, j), minPath);
			}			
		}
	}
	
	cout << minPath << '\0';
	
	return 0;
}