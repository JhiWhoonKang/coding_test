// ( ) [ ]
// ( ) : 2
// [ ] : 3

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    stack<char> st;   // ��ȣ�� ¦�� ���߱� ���� ����
    int result = 0;   // ���� ��ȣ���� ���� ������ ����
    int value = 1;    // ���� ��ȣ ������ ���� ���� ���� (������)
    int idx = 0;      // ���� ������ �ε���

    for (char ch : input) {
        if (ch == '(') {
            value *= 2;       // '('�� ������ value�� 2�� ����
            st.push(ch);      // ���ÿ� '('�� ����
        }
        else if (ch == '[') {
            value *= 3;       // '['�� ������ value�� 3�� ����
            st.push(ch);      // ���ÿ� '['�� ����
        }
        else if (ch == ')') {
            // ������ ����ְų� top�� '('�� �ƴϸ� �ùٸ��� ���� ��ȣ��
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            // �ٷ� ���� ���ڰ� '('���, ���� value�� ����� ����
            // ��, ��ȣ �ȿ� �ٸ� ���� �����Ƿ� ���� value�� ��ȣ�� ��
            if (input[idx - 1] == '(')
                result += value;
            st.pop();         // ¦�� �������Ƿ� ���ÿ��� ����
            value /= 2;       // '('�� ���� ������ 2�� ȿ�� ����
        }
        else if (ch == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (input[idx - 1] == '[')
                result += value;
            st.pop();
            value /= 3;       // '['�� ���� ������ 3�� ȿ�� ����
        }
        idx++;  // ���� ���ڷ� �̵�
    }

    // ��� ��ȣ�� ¦�� �̷��� ���ߴٸ� �ùٸ��� ���� ��ȣ����
    if (!st.empty()) {
        cout << 0;
        return 0;
    }

    cout << result;
    return 0;
}
