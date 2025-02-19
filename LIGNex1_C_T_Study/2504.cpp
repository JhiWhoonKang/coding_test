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

    stack<char> st;   // 괄호의 짝을 맞추기 위한 스택
    int result = 0;   // 최종 괄호열의 값을 저장할 변수
    int value = 1;    // 현재 괄호 구조에 따른 곱셈 인자 (누적값)
    int idx = 0;      // 현재 문자의 인덱스

    for (char ch : input) {
        if (ch == '(') {
            value *= 2;       // '('를 만나면 value에 2를 곱함
            st.push(ch);      // 스택에 '('를 저장
        }
        else if (ch == '[') {
            value *= 3;       // '['를 만나면 value에 3을 곱함
            st.push(ch);      // 스택에 '['를 저장
        }
        else if (ch == ')') {
            // 스택이 비어있거나 top이 '('가 아니면 올바르지 않은 괄호열
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            // 바로 이전 문자가 '('라면, 현재 value를 결과에 더함
            // 즉, 괄호 안에 다른 값이 없으므로 현재 value가 괄호의 값
            if (input[idx - 1] == '(')
                result += value;
            st.pop();         // 짝을 맞췄으므로 스택에서 제거
            value /= 2;       // '('에 대해 곱해진 2의 효과 제거
        }
        else if (ch == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (input[idx - 1] == '[')
                result += value;
            st.pop();
            value /= 3;       // '['에 대해 곱해진 3의 효과 제거
        }
        idx++;  // 다음 문자로 이동
    }

    // 모든 괄호가 짝을 이루지 못했다면 올바르지 않은 괄호열임
    if (!st.empty()) {
        cout << 0;
        return 0;
    }

    cout << result;
    return 0;
}
