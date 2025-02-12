#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	int cnt;
	cin >> cnt;
	
	deque<int>Deque;
	for (int i = 0;i < cnt;++i)
	{
		string input;
		cin >> input;

		if (input == "push_back")
		{
			int data;
			cin >> data;
			Deque.push_back(data);
		}
		else if (input == "push_front")
		{
			int data;
			cin >> data;
			Deque.push_front(data);
		}
		else if (input == "pop_front")
		{
			if (Deque.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << Deque.front() << endl;
				Deque.pop_front();
			}			
		}
		else if (input == "pop_back")
		{
			if (Deque.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << Deque.back() << endl;
				Deque.pop_back();
			}			
		}
		else if (input == "front")
		{
			if (Deque.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << Deque.front() << endl;
			}
		}
		else if (input == "back")
		{
			if (Deque.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << Deque.back() << endl;
			}			
		}
		else if (input == "size")
		{
			cout << Deque.size() << endl;
		}
		else if (input == "empty")
		{
			cout << Deque.empty() << endl;
		}
		else
		{
			return 0;
		}
	}	

	return 0;
}