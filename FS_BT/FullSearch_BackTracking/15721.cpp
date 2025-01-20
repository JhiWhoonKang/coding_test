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
//	cin >> A >> T >> SIGN; // SIGN 0: �� 1: ����
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
//			//��
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
//			//����
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
    cin >> A >> T >> K; // A: ��� ��, T: ��ȣ�� ��°, K: ��ȣ ����(0: "��", 1: "����")

    vector<int> players(A); // ��� ��ȣ�� ����
    for (int i = 0; i < A; ++i) {
        players[i] = i; // 0 ~ A-1 ��ȣ
    }

    int current_person = 0; // ���� ��ȣ�� ��ġ�� ��� ��ȣ
    int count = 0; // T��° ��ȣ������ ī��Ʈ
    int round = 1; // ���� ����

    while (true) {
        // "�� - ���� - �� - ����" ��Ģ
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

        // "��(x round) - ����(x round)" ��Ģ
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

        ++round; // ���� ����� ����
    }

    return 0;
}
