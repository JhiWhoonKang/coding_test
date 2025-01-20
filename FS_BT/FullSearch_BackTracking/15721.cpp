//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	int A, T, SIGN;
//	cin >> A >> T >> SIGN; // SIGN 0: 뻔 1: 데기
//
//	vector<int>players(A);
//	for (int i = 0;i < A;i++)
//	{
//		players[i] = i;
//	}
//
//	int current_person = 0;
//	int cnt = 0;
//	int round = 1;
//
//	while (true)
//	{
//		for (int i = 0;i < 4;i++)
//		{
//			if (i % 2 == SIGN)
//			{
//				cnt++;
//				if (cnt == T)
//				{
//					cout << players[current_person] << endl;
//					return 0;
//				}
//			}
//			current_person = (current_person + 1) % A;
//		}
//
//		for (int i = 0;i < round;i++)
//		{
//			//뻔
//			if (SIGN == 0)
//			{
//				++cnt;
//				if (cnt == T)
//				{
//					cout << players[current_person] << endl;
//					return 0;
//				}
//			}
//			current_person = (current_person + 1) % A;
//		}
//
//		for (int i = 0;i < round;i++)
//		{
//			//데기
//			if (SIGN == 1)
//			{
//				++cnt;
//				if (cnt == T)
//				{
//					cout << players[current_person] << endl;
//					return 0;
//				}
//			}
//			current_person = (current_person + 1) % A;
//		}
//		++round;
//	}
//
//	return 0;
//}


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, T, K;
    cin >> A >> T >> K; // A: 사람 수, T: 구호의 번째, K: 구호 종류(0: "뻔", 1: "데기")

    vector<int> players(A); // 사람 번호를 저장
    for (int i = 0; i < A; ++i) {
        players[i] = i; // 0 ~ A-1 번호
    }

    int current_person = 0; // 현재 구호를 외치는 사람 번호
    int count = 0; // T번째 구호까지의 카운트
    int round = 1; // 게임 라운드

    while (true) {
        // "뻔 - 데기 - 뻔 - 데기" 규칙
        for (int i = 0; i < 4; ++i) {
            if (i % 2 == K) {
                ++count;
                if (count == T) {
                    cout << players[current_person] << endl;
                    return 0;
                }
            }
            current_person = (current_person + 1) % A;
        }

        // "뻔(x round) - 데기(x round)" 규칙
        for (int i = 0; i < round; ++i) {
            if (K == 0) {
                ++count;
                if (count == T) {
                    cout << players[current_person] << endl;
                    return 0;
                }
            }
            current_person = (current_person + 1) % A;
        }

        for (int i = 0; i < round; ++i) {
            if (K == 1) {
                ++count;
                if (count == T) {
                    cout << players[current_person] << endl;
                    return 0;
                }
            }
            current_person = (current_person + 1) % A;
        }

        ++round; // 다음 라운드로 진행
    }

    return 0;
}
