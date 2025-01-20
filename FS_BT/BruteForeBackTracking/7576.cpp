#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int day = 0;
int N, M;
vector<vector<int>>storage;
vector<vector<bool>>visited;

int bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x, y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && storage[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
		++day;
	}

	return day;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	storage.resize(N, vector<int>(M, -1));
	visited.resize(N, vector<bool>(M, false));

	int emptyCnt = 0, tomatoCnt = 0;

	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < M;++j)
		{
			cin >> storage[i][j];
			if (storage[i][j] == 1)
			{
				tomatoCnt++;
			}
			else if (storage[i][j] == -1)
			{
				emptyCnt++;
			}
		}
	}

	int minDay = 100000000000;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (!visited[i][j] && storage[i][j] == 1)
			{
				minDay = min(bfs(i, j), minDay);
			}
		}
	}

	cout << minDay << '\0';

	return 0;
}