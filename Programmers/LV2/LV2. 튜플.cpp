#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(string a, string  b)
{
	if (a.length() > b.length())
		return false;
	else
		return true;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<string> temp;
	stringstream ss1;
	string New = s.substr(1, s.length() - 2); // 양쪽 잘라내기
	string Group;
	int size = 0;
	ss1.str(New);
	// 1. 각 원소 구분(단위자) [res : " ,{a1" ]
	while (getline(ss1, Group, '}'))
	{
		temp.push_back(Group);
	}
	size = temp.size(); // Size측정
	// 2. 괄호 전부 제거

	temp[0] = temp[0].substr(1, temp[0].length() - 1); // 처음은 {만 제거
	for (int i = 1; i < size; ++i) // 두번째부터는 ,{를 제거
	{
		temp[i] = temp[i].substr(2, temp[i].length() - 2);
	}

	// 3. 정렬
	sort(temp.begin(), temp.end(), comp);

	// 4. 입력
	for (int i = 0; i<temp.size(); ++i)
	{
		vector<int> Devide;
		string CurTemp = "";
		for (int k = 0; k < temp[i].size(); ++k)
		{
			if (temp[i][k] == ',')
			{
				Devide.push_back(stoi(CurTemp));
				CurTemp = "";
			}
			else
				CurTemp += temp[i][k];
		}
		Devide.push_back(stoi(CurTemp));
		for (int j = 0; j < Devide.size(); ++j)
		{
			if (find(answer.begin(), answer.end(), Devide[j]) == answer.end())
				answer.push_back(Devide[j]);
		}
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/64065