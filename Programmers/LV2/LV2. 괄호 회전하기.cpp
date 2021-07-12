#include<algorithm>
#include<vector>
#include<string>

using namespace std;

inline bool opencheck(char a)
{
	return(a == '(' || a == '{' || a == '[');
}

inline bool paircheck(char first, char second)
{
	return((first == '(' && second == ')') ||
		(first == '{' && second == '}') ||
		(first == '[' && second == ']'));
}

bool check(string &s)
{
	vector<char> temp;
	for (int i = 0; i < s.length() ;++i)
	{
		if (opencheck(s[i]))
			temp.push_back(s[i]);
		else if (!temp.empty() && paircheck(temp.back(), s[i]))
			temp.pop_back();
		else
			return false;
	}
	if (!temp.empty())
		return false;
	return true;
}

int solution(string s)
{
	int answer = 0;
	string temp;
	if (s.length() % 2 == 1)
		return 0;
	for (int i = 0; i < s.length(); ++i)
	{
		temp = s.substr(i) + s.substr(0, i);
		if (check(temp))
			answer++;
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/76502