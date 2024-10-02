#include <iostream>
#include <queue>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	
	std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
	
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		if (N == 0)
		{
			std::cout << N << '\n';
		}
		else
		{
			std::cout << N << '\n';
		}
	}

	return 0;
}