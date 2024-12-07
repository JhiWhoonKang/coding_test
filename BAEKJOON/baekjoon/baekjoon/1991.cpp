#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
	char left;
	char right;
};

unordered_map<char, Node> tree;

void preorder(char root)
{
	if (root == '.')
	{
		return;
	}
	cout << root;
	preorder(tree[root].left);
	preorder(tree[root].right);
}

void inorder(char root)
{
	if (root == '.') return;
	inorder(tree[root].left);
	cout << root;
	inorder(tree[root].right);
}

void postorder(char root)
{
	if (root == '.') return;
	postorder(tree[root].left);
	postorder(tree[root].right);
	cout << root;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	if (N < 1 || N>26)
	{
		return 0;
	}

	vector<char>ch(N);
	for (int i = 0; i < N; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		tree[parent] = { left, right };
	}

	preorder('A');
	cout << '\n';

	inorder('A');
	cout << '\n';

	postorder('A');
	cout << '\n';

	return 0;
}