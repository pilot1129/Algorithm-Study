#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
	vector<string> KeyList;
	int answer = 1;
	unordered_map<string, int> SpyCloth;
	for (unsigned int i = 0; i < clothes.size(); ++i)
	{
		unordered_map<string, int>::const_iterator Iter = SpyCloth.find(clothes[i][1]);
		if (Iter == SpyCloth.end())
		{
			SpyCloth.insert(make_pair(clothes[i][1], 1));
			KeyList.push_back(clothes[i][1]);
		}
		else
		{
			int Temp = Iter->second+1;
			SpyCloth.at(clothes[i][1]) = Temp;
		}
	}
	for (unsigned int i = 0; i < KeyList.size(); ++i)
	{
		answer *= SpyCloth.at(KeyList[i]) + 1;
	}
	answer--;
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42578