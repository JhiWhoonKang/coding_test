#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>tree;
vector<bool>visited;

int func(int node, int depth)
{
	visited[node] = true;
	int total_depth = 0;
	bool is_leaf = true;

	for (int child : tree[node])
	{
		if (!visited[child])
		{
			is_leaf = false;
			total_depth += func(child, depth + 1);
		}
	}

	if (is_leaf)
	{
		return depth;
	}

	return total_depth;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	if (N < 2 || N>500000)
	{
		return 0;
	}

	tree.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < 1 || b<1 || a>N || b>N || a == b)
		{
			return 0;
		}

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int total_leaf_depth = func(1, 0);

	if (total_leaf_depth % 2 == 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}