#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
	string answer;
	vector<vector<string>> Database;
	for (auto i = 0; i < table.size(); ++i)
	{
		string Temp;
		vector<string> Tempvec;
		stringstream ss;
		ss.str(table[i]);
		while (ss >> Temp)
		{
			Tempvec.push_back(Temp);
		}
		Database.push_back(Tempvec);
	}
	vector<int> Score;
	for (auto i = 0; i < Database.size(); ++i)
	{
		Score.push_back(0);
		for (auto j = 0; j < languages.size(); ++j)
		{
			auto iter = find(Database[i].begin(), Database[i].end(), languages[j]);
			if (iter != Database[i].end())
			{
				Score[i] += (6 - (iter - Database[i].begin())) * preference[j];
			}
		}
	}

	unsigned int max = Score[0];
	queue<int> MaxElem;
	MaxElem.push(0);
	for (int i = 1; i < Score.size(); ++i)
	{
		if (Score[i] > max)
		{
			max = Score[i];
			MaxElem.push(i);
			MaxElem.pop();
		}
		else if (Score[i] == max)
			MaxElem.push(i);
	}

	if (MaxElem.size() == 1)
		return Database[MaxElem.front()][0];
	else
	{
		string Max, Cur;
		Max = Database[MaxElem.front()][0];
		MaxElem.pop();
		for (auto i = 1; i < MaxElem.size()+1; ++i)
		{
			Cur = Database[MaxElem.front()][0];
			MaxElem.pop();
			if (Max[0] > Cur[0])
				Max = Cur;
		}
		answer = Max;
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/84325