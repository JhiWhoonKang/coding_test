#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int rev(int);

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int X, Y, total;
	cin >> X >> Y;
	
	if (X < 1 || Y < 1 || X>1000 || Y>1000)
	{
		return 0;
	}	

	X = rev(X);
	Y = rev(Y);

	total = rev(X + Y);
	cout << total;

	return 0;
}

int rev(int n)
{
	string s;
	s = to_string(n);	
	reverse(s.begin(), s.end());
	
	return stoi(s);
}