#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<bool> submitted(31, false);
    int num;

    for (int i = 0; i < 28; i++) 
    {
        cin >> num;
        submitted[num] = true;
    }

    for (int i = 1; i <= 30; i++) 
    {
        if (!submitted[i]) 
        {
            cout << i << endl;
        }
    }

    return 0;
}