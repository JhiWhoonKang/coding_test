#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> paper;
vector<vector<bool>> visited;
int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x, y });
	visited[x][y] = true;
	int area = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++)
		{			
			int nx = cx + dx[i];			
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && paper[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
				++area;		
			}
		}
	}
	return area;
 }

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	paper.resize(n, vector<int>(m, -1));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> paper[i][j];
		}
	}
	
	int cnt = 0;
	int maxArea = 0;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (paper[i][j] == 1 && !visited[i][j])
			{
				cnt++;
				maxArea = max(maxArea, bfs(i, j));
			}
		}
	}

	cout << cnt << "\n" << maxArea << "\n";
	
	return 0;
}