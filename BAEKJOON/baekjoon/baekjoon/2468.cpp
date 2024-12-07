#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>>graph;
vector<vector<bool>>visited;
int N;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void searching(int x, int y, int rain_height)
{
	queue<pair<int, int>>q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;		
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && graph[nx][ny] > rain_height)
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	graph.resize(N, vector<int>(N));
	int max_height = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
			max_height = max(max_height, graph[i][j]);
		}
	}

	int max_safe_area = 0;
	for (int rain_height = 0; rain_height <= max_height; rain_height++)
	{
		visited.assign(N, vector<bool>(N, false));
		int safe_areas = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && graph[i][j] > rain_height)
				{
					searching(i, j, rain_height);
					safe_areas++;
				}
			}
		}
		max_safe_area = max(max_safe_area, safe_areas);
	}

	cout << max_safe_area << endl;

	return 0;
}