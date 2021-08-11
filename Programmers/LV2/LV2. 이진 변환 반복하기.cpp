#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) 
{
	vector<int> answer;
	string FixString = s;
	int count = 0;
	int deletecount = 0;
	while (FixString.compare("1") != 0)
	{
		int OneCount = 0;
		for (unsigned int i = 0; i < FixString.length(); i++)
		{
			if (FixString[i] == '1')
				OneCount++;
			else
				deletecount++;
		}
		FixString = "";
		while (OneCount != 0)
		{
			FixString += to_string(OneCount % 2);
			OneCount /= 2;
		}
		reverse(FixString.begin(), FixString.end());
		count++;
	}
	answer.push_back(count);
	answer.push_back(deletecount);
	return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/70129