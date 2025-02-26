#include <iostream>
#include <set>


using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	// 들어오는 간선 x -> root node
	// root node 제외 node <- 들어오는 간선 존재
	// root node -> 다른 node로 이동 가능

	int u, v;		// node u, v
	bool isFinish = false;
	// 입력의 끝; 두 개의 음수 존재
	// 각 테스트 케이스 끝: 두 개의 0 존재

	while (true)
	{
		set<int>node;
		cin >> u >> v;
		if (u < 0 && v < 0)
		{
			break;
		}

		if (u == 0 && v == 0)
		{
			break;
		}

		node.insert(u);
		node.insert(v);
	}

	return 0;
}