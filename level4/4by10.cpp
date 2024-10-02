#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> scores(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> scores[i];
    }

    double maxScore = *max_element(scores.begin(), scores.end());

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (scores[i] / maxScore) * 100;
    }

    cout << fixed;
    cout.precision(6); 
    cout << sum / N << endl;

    return 0;
}
