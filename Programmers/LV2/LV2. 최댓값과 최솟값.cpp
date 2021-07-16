#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	string temp = "";
	stringstream ss;
	ss.str(s);
	int min, max;
	int i = 0;
	while (ss >> temp)
	{
		if (i == 0)
		{
			min = atoi(temp.c_str());
			max = atoi(temp.c_str());
		}
		int tempnum = atoi(temp.c_str());
		if (tempnum < min)
			min = tempnum;
		else if (tempnum > max)
			max = tempnum;
		i++;
	}
	answer += to_string(min);
	answer += " ";
	answer += to_string(max);
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12939