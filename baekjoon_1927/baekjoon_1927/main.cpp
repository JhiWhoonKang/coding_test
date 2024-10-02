#include <iostream>
#include <queue>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;
		if (x == 0)
		{
			if (minHeap.empty())
			{
				std::cout << "0" << '\n';
			}
			else
			{
				std::cout << minHeap.top() << '\n';
				minHeap.pop();
			}
		}
		else
		{
			minHeap.push(x);
		}

	}

	return 0;
}