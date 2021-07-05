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
	string New = s.substr(1, s.length() - 2); // ���� �߶󳻱�
	string Group;
	int size = 0;
	ss1.str(New);
	// 1. �� ���� ����(������) [res : " ,{a1" ]
	while (getline(ss1, Group, '}'))
	{
		temp.push_back(Group);
	}
	size = temp.size(); // Size����
	// 2. ��ȣ ���� ����

	temp[0] = temp[0].substr(1, temp[0].length() - 1); // ó���� {�� ����
	for (int i = 1; i < size; ++i) // �ι�°���ʹ� ,{�� ����
	{
		temp[i] = temp[i].substr(2, temp[i].length() - 2);
	}

	// 3. ����
	sort(temp.begin(), temp.end(), comp);

	// 4. �Է�
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