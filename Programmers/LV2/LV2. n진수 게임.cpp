#include <string>
#include <vector>

using namespace std;

string Convert(int num, int n) 
{
	char code[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	string temp = "";
	while (num / n != 0) 
	{
		temp = code[num%n] + temp;
		num = num / n;
	}
	temp = code[num%n] + temp;
	return temp;
}

string solution(int n, int t, int m, int p) 
{
	string answer = "";
	string temp = "";

	// 임시 배열 tmp에 t*m 정도의 숫자를 담는다.
	int count = 0;
	while (temp.length() <= t * m)
	{
		temp += Convert(count, n);
		count++;
	}

	count = 0;
	for (auto i = 0; i < temp.length(); ++i)
	{
		if (count == t)
			break;
		if (i % m == (p - 1))
		{
			answer += temp[i];
			count++;
		}
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/17687