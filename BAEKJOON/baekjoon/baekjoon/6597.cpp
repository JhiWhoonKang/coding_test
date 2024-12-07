#include <iostream>
#include <string>

using namespace std;

void postorder(const string& preorder, const string& inorder, int pre_start, int in_start, int length)
{
	if (length <= 0)
	{
		return;
	}

	char root = preorder[pre_start];
	int root_index = inorder.find(root, in_start);
	int left_length = root_index - in_start;

	postorder(preorder, inorder, pre_start + 1, in_start, left_length);

	postorder(preorder, inorder, pre_start + 1 + left_length, root_index + 1, length - left_length - 1);

	cout << root;
}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	string preorder, inorder;
	while (cin >> preorder >> inorder)
	{
		if (preorder.size() != inorder.size() || preorder.size() > 26 || inorder.size() > 26)
		{
			return 0;
		}

		int length = preorder.size();
		postorder(preorder, inorder, 0, 0, length);
	}
	
	return 0;
}