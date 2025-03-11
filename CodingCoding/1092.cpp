#include <iostream>
#include <vector>
<<<<<<< HEAD:Tree/1092.cpp
=======
#include <map>
>>>>>>> 25bb4e218b83093ff0937c0518d9b06abf09d78c:CodingCoding/1092.cpp
#include <algorithm>

using namespace std;

int main(void)
{
<<<<<<< HEAD:Tree/1092.cpp
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
=======
	int N;	// 크레인 수
	int M;	// 박스 수
	cin >> N;						// 크레인 수 입력
	vector<int>limit_weights(N);	// 각 크레인 무게 한계 저장	
	for (int i = 0; i < N; ++i)
	{
		cin >> limit_weights[i];
	}

	cin >> M;						// 박스 수 입력
	vector<vector<int>>box_weights(M, vector<int>(2));		// 각 박스 무게 저장
															// [i][0]: 무게
															// [i][1]: 선택 여부, 0: x, 1: o
	for (int i = 0; i < M; ++i)
	{
		cin >> box_weights[i][0];
		box_weights[i][1] = 1;
	}

	sort(limit_weights.begin(), limit_weights.end(), greater<int>());
	sort(box_weights.begin(), box_weights.end(), [](const vector<int>& a, const vector<int>& b)
												{
												return a[0] > b[0];
												});

	int time = 0;
	if (limit_weights[0] < box_weights[0])
	{
		cout << -1;
		return 0;
	}


>>>>>>> 25bb4e218b83093ff0937c0518d9b06abf09d78c:CodingCoding/1092.cpp

	return 0;
}