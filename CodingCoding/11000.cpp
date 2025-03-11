#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() 
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;      // 수업 수
    cin >> N;

    vector<pair<int, int>> classes(N);      // 강의실
                                            // first: Si(시작 시간), second: Ti(종료 시간)

    for (int i = 0; i < N; ++i)
    {
        cin >> classes[i].first >> classes[i].second;
    }

    sort(classes.begin(), classes.end());       // Si -> Bi 정렬

    priority_queue<int, vector<int>, greater<int>> pq;      // 숫자 큰 것 부터 우선순위 큐
    for (auto studyClass : classes)
    {
        int startTime = studyClass.first;      // 시작 시간
        int endTime = studyClass.second;       // 종료 시간

        // 기존 강의실 중 가장 먼저 끝나는 강의실 찾기    
        if (!pq.empty() && pq.top() <= startTime)      // T_i <= S_j 인 경우까지 가능(i: i 수업, j: j 수업)
        {
            pq.pop();
        }

        pq.push(endTime);
    }


    cout << pq.size() << "\n";

    return 0;
}