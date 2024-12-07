#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    string input, bomb;
    cin >> input >> bomb;

    if (input.length() < 1 || input.length() > 1000000 || bomb.length() < 1 || bomb.length() > 36) 
    {
        return 0;
    }

    string result = "";
    int bomb_len = bomb.length();

    for (char ch : input) {
        result.push_back(ch);
        if (result.length() >= bomb_len && result.substr(result.length() - bomb_len) == bomb) 
        {
            result.erase(result.length() - bomb_len);
        }
    }

    if (result.empty()) {
        cout << "FRULA" << '\n';
    }
    else {
        cout << result << '\n';
    }

    return 0;
}
