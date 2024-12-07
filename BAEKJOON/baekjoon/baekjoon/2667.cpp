#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>>map;
vector<vector<bool>>visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y, int size)
{	
	queue<pair<int, int>>q;
	q.push({ x, y });
	visited[x][y] = true;
	int cnt = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;		
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < size && ny < size && !visited[nx][ny] && map[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				cnt++;
				q.push({ nx, ny });
			}
		}
	}

	return cnt;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	map.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{			
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	vector<int>complex_size;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				complex_size.push_back(bfs(i, j, N));
			}
		}
	}

	sort(complex_size.begin(), complex_size.end());
	cout << complex_size.size() << endl;
	for (int i : complex_size)
	{
		cout << i << endl;
	}

	return 0;
}