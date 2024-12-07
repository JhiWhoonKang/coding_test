#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
	int left;
	int right;
};

unordered_map<int, Node>tree;

int main(void)
{
	int N;
	cin >> N;
	if (N < 2 || N>100000)
	{
		return 0;
	}

	for (int i = 1; i < N; i++)
	{
		int left, right;
		cin >> left >> right;
		tree[i]
	}

	return 0;
}