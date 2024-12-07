#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node
{
	int left;
	int right;
};

int K;
vector<vector<Node>>tree;

void searching(int left, int length)
{


}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> K;

	tree.resize(K);

	for (int i = 1; i < pow(2, K); i++)
	{
		cin >> tree[i];
	}
	searching();

	return 0;
}