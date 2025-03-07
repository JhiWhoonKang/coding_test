#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;	// 크레인의 수
	int M;	// 박스의 수

	cin >> N;
	vector<int> crane(N);	// 각 크레인 무게제한
	for (int i = 0;i < N;++i)
	{
		cin >> crane[i];
	}

	cin >> M;
	vector<int> box(M);		// 각 박스 무게
	for (int i = 0;i < M;++i)
	{
		cin >> box[i];
	}

	sort(crane.rbegin(), crane.rend());	// 크레인 무게 제한 내림차순 정렬
	sort(box.rbegin(), box.rend());		// 박스 무게 내림차순 정렬

	if (crane[0] < box[0])		// 크레인 최대 무게 제한이 박스 최대 무게보다 작으면 끝
	{
		cout << -1 << "\n";
		return 0;
	}

	vector<bool> move(M, false);  // 박스 옮기기
	int time = 0;
	int moved = 0;

	while (moved < M) 
	{
		int idx = 0;
		for (int i = 0; i < N; i++) 
		{
			while (idx < M) 
			{
				// 크레인이 옮길 수 있는지 여부
				if (!move[idx] && box[idx] <= crane[i]) 
				{
					move[idx] = true;
					++moved;
					break;
				}
				++idx;
			}
		}
		++time;
	}

	cout << time << "\n";

	return 0;
}