#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> tower(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> tower[i];
	}

	vector<int>result(N, 0);
	stack<int>big;
	for (int i = 0; i < N; ++i)
	{
		// ���� ž vs ���� ž
		while (!big.empty() && tower[big.top()] < tower[i])	// ���� ž�� �� ŭ
		{
			big.pop();
		}
		// => ���� ���� ����� ���� Ÿ�� ��ȣ�� �ֻ��

		
		if (big.empty())	// ����ִ� = ��� ������ �۾ҵ�
		{
			result[i] = 0;
		}
		else				// ���� ����ִ� = ������ ū�� �־��� = ī��Ʈ ����
		{
			result[i] = big.top() + 1;
		}

		big.push(i);
	}

	for (int i = 0; i < N; ++i) 
	{
		cout << result[i] << " ";
	}

	return 0;
}