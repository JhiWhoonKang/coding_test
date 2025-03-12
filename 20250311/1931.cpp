#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;		// 회의 개수
	cin >> N;

	vector<pair<int, int>>conference(N);	// <startTime, endTime>
	for (int i = 0; i < N; ++i)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		conference[i] = { startTime, endTime };
	}

	sort(conference.begin(), conference.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
	{
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});

    int cnt = 0;
    int prev_end_time = 0;
    for (auto& conf : conference)
    {
        int endtime = conf.first;
        int starttime = conf.second;

        if (starttime >= prev_end_time) 
        {
            ++cnt;
            prev_end_time = endtime;
        }
    }

    cout << cnt << "\n";

	return 0;
}

/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N); // pair: {끝나는 시간, 시작 시간}

    for (int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        meetings[i] = {end, start};
    }

    // 종료시간 기준으로 오름차순 정렬, 종료시간이 같다면 시작시간 기준으로 정렬
    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    int count = 0;
    int last_end = 0; // 회의 시간이 0부터 시작할 수 있으므로 적절한 초기값 설정
    for (auto &meeting : meetings) {
        int end = meeting.first;
        int start = meeting.second;
        if (start >= last_end) {  // 회의가 이전 회의 종료시간 이후에 시작하면 선택
            count++;
            last_end = end;
        }
    }

    cout << count << "\n";
    return 0;
}


*/