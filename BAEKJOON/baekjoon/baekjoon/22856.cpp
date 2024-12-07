#include <iostream>
#include<vector>

using namespace std;

struct Node
{
	int left;
	int right;
};

vector<Node>tree;
vector<bool> visited;


int pseudo_inorder_traversal(int node, int moved)
{
	while (true)
	{
		while (tree[node].left != -1 && !visited[tree[node].left])
		{
			node = tree[node].left;
			moved++;
		}

		if (!visited[node])
		{
			visited[node] = true;
		}

		if (tree[node].right != -1 && !visited[tree[node].right])
		{
			node = tree[node].right;
			moved++;
			continue;
		}

		if(node)

		visited[node] = true;
		for (int next : tree[node])
		{
			if (!visited[next])
			{
				pseudo_inorder_traversal(next, moved + 1);
			}
		}

		return moved;
	}
	
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	if (N < 1 || N>100000)
	{
		return 0;
	}

	tree.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a<1 || b<1 || a>N || b>N)
		{
			return 0;
		}

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int total_moved = inorder_traversal(1, 0);

	cout << total_moved << '\0';

	return 0;
}