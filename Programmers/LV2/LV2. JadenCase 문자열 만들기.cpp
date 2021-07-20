#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

string solution(string s) {
	string answer = "";
	string temp;
	stringstream ss;
	ss.str(s);

	bool bef = false;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			bef = false;
			answer += " ";
		}
		else
		{
			if (!bef)
			{
				answer += toupper(s[i]);
				bef = true;
			}
			else
				answer += tolower(s[i]);
		}
	}
	return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/12951#