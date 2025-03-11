#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
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



	return 0;
}