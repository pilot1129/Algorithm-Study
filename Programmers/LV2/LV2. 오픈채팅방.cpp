#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;

void Change(unordered_map<string, string>& id, string ID, string Name)
{
	if (id.find(ID) != id.end()) // if find
		id.find(ID)->second = Name;
	else
		id.insert(make_pair(ID, Name));
}

void Input(string rec, queue<pair<string, string>>& stat, unordered_map<string, string>& id)
{
	string Order[3];
	stringstream Temp(rec);
	for (int i = 0; i < 3; ++i)
		Temp >> Order[i];

	if (Order[0] == "Enter")
	{
		stat.push(make_pair(Order[0], Order[1]));
		Change(id, Order[1], Order[2]);
	}
	else if (Order[0] == "Leave")
		stat.push(make_pair(Order[0], Order[1]));
	else // change
		Change(id, Order[1], Order[2]);
}




vector<string> solution(vector<string> record)
{
	vector<string> ans;
	unordered_map<string, string> ID_Name;
	queue<pair<string, string>> STAT_ID;
	
	for (int i = 0; i < record.size(); ++i)
	{
		Input(record[i], STAT_ID, ID_Name);
	}
	
	int size = STAT_ID.size();
	for (int i = 0; i < size; ++i)
	{
		string Temp;
		Temp = ID_Name.find(STAT_ID.front().second)->second;
		if (STAT_ID.front().first == "Enter")
			Temp += "님이 들어왔습니다.";
		else
			Temp += "님이 나갔습니다.";
		ans.push_back(Temp);
		STAT_ID.pop();
	}
	return ans;
}
//https://programmers.co.kr/learn/courses/30/lessons/42888