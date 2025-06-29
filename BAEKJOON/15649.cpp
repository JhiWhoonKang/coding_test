#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> result;
vector<bool> visited;

void dfs(int depth) 
{
    if (depth == M) 
	{
        for (const auto& num : result) 
		{
			cout << num << " ";
		}
        cout << '\n';
        
		return;
    }

    for (int i = 1; i <= N; ++i) 
	{
        if (!visited[i]) 
		{
            visited[i] = true;
            result.push_back(i);
            dfs(depth + 1);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main() 
{
    cin >> N >> M;
    visited.resize(N + 1, false);
    dfs(0);
}
