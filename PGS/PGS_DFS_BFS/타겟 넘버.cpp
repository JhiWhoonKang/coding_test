#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<int>& numbers, int target, int idx, int curSum)
{
    if (idx == numbers.size())
    {
        return curSum == target ? 1 : 0;
    }

    int add = dfs(numbers, target, idx + 1, curSum + numbers[idx]);
    int sub = dfs(numbers, target, idx + 1, curSum - numbers[idx]);

    return add + sub;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    for (const auto n : numbers)
    {
        cout << n << "\n";
    }

    answer = dfs(numbers, target, 0, 0);

    return answer;
}