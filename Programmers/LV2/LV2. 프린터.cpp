#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> Printerpair;
	pair<int,int> findnum;
	for (int i = 0; i < priorities.size(); ++i)
	{
		Printerpair.push(make_pair(i, priorities[i]));
		if (i == location)
		{
			findnum.first = i;
			findnum.second = priorities[i];
		}
	}
	sort(priorities.begin(), priorities.end(), greater<int>());


	while (!Printerpair.empty())
	{
		for (int i = 0; i < Printerpair.size(); ++i)
		{
			pair<int, int> temp = Printerpair.front();
			Printerpair.pop();
			if (temp.second == priorities[answer])
			{
				answer++;
				if (findnum.second == temp.second && findnum.first == temp.first)
					return answer;
			}
			else
				Printerpair.push(temp);
		}
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42587