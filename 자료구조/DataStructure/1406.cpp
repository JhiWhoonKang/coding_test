#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	string input;
	int cmd_num;
	stack<char> left, right;

	cin >> input;		
	if (input.length() > 600000)
	{
		return 0;
	}

	for (char c : input)
	{
		if (!isalpha(c))
		{
			return 0;
		}
		if (!islower(c))
		{
			return 0;
		}

		left.push(c);
	}

	cin >> cmd_num;

	for (int i = 0; i < cmd_num; i++)
	{
		char cmd;
		cin >> cmd;		

		if (cmd == 'L')
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}

		else if (cmd == 'D')
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}

		else if (cmd == 'B')
		{
			if (!left.empty())
			{
				left.pop();
			}			
		}

		if (cmd == 'P')
		{
			char added;
			cin >> added;

			left.push(added);
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	return 0;
}