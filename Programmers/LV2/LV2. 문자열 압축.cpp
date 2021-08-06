#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	string Shortest = s;

	for (int i = 1; i <= s.length() / 2; ++i)
	{
		int LoopNum = 1;
		string BefStr = "";
		string CurFullStr = "";

		for (int j = 0; j < s.length(); j += i)
		{
			string CurStr = s.substr(j, i);
			if (i + j > s.length()-1)
			{
				if (BefStr == CurStr)
				{
					CurFullStr += to_string(LoopNum+1);
					CurFullStr += BefStr;
				}
				else
				{
					if (LoopNum > 1)
						CurFullStr += to_string(LoopNum);
					CurFullStr += BefStr;
					CurFullStr += CurStr;
					LoopNum = 1;
				}
			}
			else if (j != 0)
			{
				if (BefStr == CurStr)
					LoopNum++;
				else
				{
					if (LoopNum > 1)
						CurFullStr += to_string(LoopNum);
					CurFullStr += BefStr;
					LoopNum = 1;
				}
			}
			BefStr = CurStr;
		}
		if (CurFullStr.length() < Shortest.length())
			Shortest = CurFullStr;
	}
	return Shortest.length();
}
//https://programmers.co.kr/learn/courses/30/lessons/60057