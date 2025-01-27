#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T Max(T a, T b)
{
	return T;
}

template<>
char* Max(char* a, char* b)
{

}

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	// queue ����
	queue<int> q;
	for (int i = 0; i < N; ++i)
	{
		// ��ɾ� �Է�
		string cmd;
		cin >> cmd;

		// ���� ��ɾ ���� if�� �б�
		if (cmd == "push")
		{
			int data;
			cin >> data;
			q.push(data);
		}
		else if (cmd == "pop")
		{
			cout << (q.empty() ? -1 : q.front()) << "\n"; // q�� ������ ��������c �� ��(q.front) data ���
			if (!q.empty()) q.pop(); // q�� ������ ��������� �� �� data pop
		}
		else if (cmd == "size")
		{
			cout << q.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (cmd == "front")
		{
			cout << (q.empty() ? -1 : q.front()) << "\n";
		}
		else //"back"
		{
			cout << (q.empty() ? -1 : q.back()) << "\n";
		}
	}

	return 0;
}

// �߰������� "\n" ���� endl���� �ϸ� �ð� �ʰ� �߻�