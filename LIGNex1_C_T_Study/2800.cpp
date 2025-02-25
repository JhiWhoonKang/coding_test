#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

// 쌍이 되는 괄호만 제거 가능
string math;
vector<pair<int, int>> _pair;                // 괄호 짝
stack<int> stk;                             // 괄호 관련 스택
vector<string> result;                         // 식들 저장

void dfs(int index, vector<bool>& removed, bool removedOne) 
{
    // 모든 괄호 쌍에 대해 결정한 경우
    if (index == _pair.size()) 
    {
        // 하나 이상의 괄호 쌍이 제거된 경우에만 결과에 추가
        if (removedOne) {
            string tmp;
            for (int i = 0; i < math.size(); i++) {
                if (!removed[i])
                {
                    tmp.push_back(math[i]);
                }                    
            }
            result.push_back(tmp);
        }
        return;
    }

    // 현재 괄호 쌍을 제거하지 않는 경우: 그대로 진행
    dfs(index + 1, removed, removedOne);

    // 현재 괄호 쌍을 제거하는 경우
    int openIdx = _pair[index].first;
    int closeIdx = _pair[index].second;
    removed[openIdx] = true;
    removed[closeIdx] = true;

    dfs(index + 1, removed, true);

    // 재귀 호출 후 원상 복구 (백트래킹)
    removed[openIdx] = false;
    removed[closeIdx] = false;
}

int main() 
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    
    cin >> math;

    

    for (int i = 0; i < math.size(); ++i)       // 괄호 짝 찾기
    {
        if (math[i] == '(')                     // 여는거 -> 스택 넣기
        {
            stk.push(i);
        }
        else if (math[i] == ')')                // 닫는거 -> 스택 빼기
        {
            int idx = stk.top();                // 여는 인덱스
            stk.pop();                          // 닫는 인덱스
            _pair.push_back({ idx, i });         // 쌍이 되는 괄호 인덱스 저장
        }
    }

   
    int pairSize = _pair.size();

    vector<bool> removed(math.size(), false);

    // 재귀 호출을 통해 괄호 제거 조합 생성 (index 0부터, 아직 아무 쌍도 제거하지 않았으므로 false)
    dfs(0, removed, false);

    // 순서대로 출력
    for (auto& s : result) 
    {
        cout << s << "\n";
    }

    return 0;
}
