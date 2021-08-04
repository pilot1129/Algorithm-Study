#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string Numberlist[10] = { "zero","one", "two","three", "four", "five", "six", "seven", "eight", "nine" };

int CheckNumber(string curstr)
{
	for (int i = 0; i < 10; ++i)
	{
		if (curstr.compare(Numberlist[i]) == 0)
			return i;
	}
	return -1;
}

int solution(string s) 
{
	string CurWord = "";
	string answer = "";
	bool Check = false;

	for (int i = 0; i < s.length(); ++i)
	{
		if (isalpha(s[i]) == 0) // 숫자라면
		{
			Check = false;
			answer += s[i];
		}
		else if (Check && isalpha(s[i]) != 0)
		{
			CurWord += tolower(s[i]);
		}
		else 
		{
			CurWord += tolower(s[i]);
			int temp = CheckNumber(CurWord);
			if (temp != -1)
			{
				answer += to_string(temp);
				Check = false;
				CurWord = "";
			}
		}
	}
	return stoi(answer);
}
//https://programmers.co.kr/learn/courses/30/lessons/81301