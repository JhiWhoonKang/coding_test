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

	// queue 생성
	queue<int> q;
	for (int i = 0; i < N; ++i)
	{
		// 명령어 입력
		string cmd;
		cin >> cmd;

		// 이하 명령어에 따른 if문 분기
		if (cmd == "push")
		{
			int data;
			cin >> data;
			q.push(data);
		}
		else if (cmd == "pop")
		{
			cout << (q.empty() ? -1 : q.front()) << "\n"; // q에 데이터 들어있으멵 맨 앞(q.front) data 출력
			if (!q.empty()) q.pop(); // q에 데이터 들어있으면 맨 앞 data pop
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

// 추가적으로 "\n" 말고 endl으로 하면 시간 초과 발생