#include <string>
#include <vector>

using namespace std;

int Number(char wd)
{
	switch (wd)
	{
	case 'A':
		return 0;
	case 'E':
		return 1;
	case 'I':
		return 2;
	case 'O':
		return 3;
	case 'U':
		return 4;
	default:
		return -1;
	}
}
int solution(string word) 
{
	int answer = 0;
	int wordlen = word.length();
	for (auto i = 0; i < word.length(); ++i)
	{
		char Cur = word[i];
		switch (i)
		{
		case 0:
			answer += Number(Cur) * 781 + 1;
			break;
		case 1:
			answer += Number(Cur) * 156 + 1;
			break;
		case 2:
			answer += Number(Cur) * 31 + 1;
			break;
		case 3:
			answer += Number(Cur) * 6 + 1;
			break;
		case 4:
			answer += Number(Cur)+ 1;
			break;
		}
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/84512