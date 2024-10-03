#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int calculate(string, string);

int main(void)
{
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	string en_name;
	unsigned short N;

	cin >> en_name;
	if (en_name.size() < 1 || en_name.size() > 20)
	{
		return 0;
	}
	transform(en_name.begin(), en_name.end(), en_name.begin(), ::toupper);	

	cin >> N;
	if (N < 1 || N > 50)
	{
		return 0;
	}

	vector<string> team_name(N);
	vector<unsigned short>score(N, 0);
	unsigned short max_score = 0;
	unsigned short max_team = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> team_name[i];

		if (team_name[i].size() < 1 || team_name[i].size() > 20)
		{
			return 0;
		}

		transform(team_name[i].begin(), team_name[i].end(), team_name[i].begin(), ::toupper);

		score[i] = calculate(en_name, team_name[i]);		
		if(score[i]>max_score)
		{
			max_score = score[i];
			max_team = i;
		}
		else if ((score[i] == max_score) && (team_name[i]<team_name[max_team]))
		{
			max_team = i;
		}
	}

	cout << team_name[max_team];

	//auto max_value = max_element(score.begin(), score.end());
	//cout << "max value: " << *max_value << endl;
	
	return 0;
}

int calculate(string name, string team)
{
	unsigned short L = 0, O = 0, V = 0, E = 0;
	string full = name + team;

	for (char c : full)
	{
		if (c == 'L')
		{
			L++;
		}

		else if (c == 'O')
		{
			O++;
		}

		else if(c=='V')
		{
			V++;
		}

		else if (c == 'E')
		{
			E++;
		}
	}

	int probability = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

	return probability;
}