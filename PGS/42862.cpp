#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 여벌 체육복 가진 학생이 도난당했으면 우선 처리
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 자기 자신이 여벌 가져왔던 경우 제거
    for (auto it = lost.begin(); it != lost.end(); ) {
        auto findIt = find(reserve.begin(), reserve.end(), *it);
        if (findIt != reserve.end()) {
            it = lost.erase(it);
            reserve.erase(findIt);
        } else {
            ++it;
        }
    }

    answer = n - lost.size(); // 기본 참석 인원

    for (auto it = lost.begin(); it != lost.end(); ) {
        auto findIt = find(reserve.begin(), reserve.end(), *it - 1);
        if (findIt != reserve.end()) {
            answer++;
            reserve.erase(findIt);
            it = lost.erase(it);
            continue;
        }

        findIt = find(reserve.begin(), reserve.end(), *it + 1);
        if (findIt != reserve.end()) {
            answer++;
            reserve.erase(findIt);
            it = lost.erase(it);
            continue;
        }
        
        ++it;
    }

    cout << "Answer: " << answer << "\n";    
    return answer;
}
