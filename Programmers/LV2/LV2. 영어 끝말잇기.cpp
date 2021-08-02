#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;
	int count = 0;
	pair<int, int> errorpair = { 999,999 };
	pair<int, int> overlappair = { 999,999 };

	//1. 끝말잇기 체크
	for (int i = 0; i < words.size() - 1; ++i)
	{
		if (words[i].back() != words[i + 1][0])
		{
			errorpair.first = (i + 1) % n + 1;
			errorpair.second = (i + 1) / n + 1;
			break;
		}
	}

	//2. 중복 확인
	unordered_map<string, int> CheckHash;
	for (int i = 0; i < words.size(); ++i)
	{
		unordered_map<string, int>::iterator Finditer = CheckHash.find(words[i]);
		if (Finditer != CheckHash.end())
		{
			overlappair.first = (i%n + 1);
			overlappair.second = (i / n + 1);
			break;
		}
		CheckHash.insert(make_pair(words[i], 1));
	}

	if (overlappair.second > errorpair.second)
	{
		answer.push_back(errorpair.first);
		answer.push_back(errorpair.second);
	}
	else if (overlappair.second < errorpair.second)
	{
		answer.push_back(overlappair.first);
		answer.push_back(overlappair.second);
	}
	else
	{
		if (errorpair.first == 999)
		{
			answer.push_back(0);
			answer.push_back(0);
		}
		else if (overlappair.first > errorpair.first)
		{
			answer.push_back(errorpair.first);
			answer.push_back(errorpair.second);
		}
		else
		{
			answer.push_back(overlappair.first);
			answer.push_back(overlappair.second);
		}
	}

	return answer;
}

int main()
{
	vector<string> a{ "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	solution(3, a);
}
//https://programmers.co.kr/learn/courses/30/lessons/12981