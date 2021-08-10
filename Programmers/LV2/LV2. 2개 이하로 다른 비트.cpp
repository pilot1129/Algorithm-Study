#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); ++i)
	{
		long long TempNum = numbers[i];
		long long Res = TempNum;
		int Count = 0;
		int BefNum = -1;
		if (TempNum % 2 == 0)
			answer.push_back(TempNum + 1);
		else
		{
			while (TempNum % 2 == 1)
			{
				Count++;
				TempNum /= 2;
			}
			answer.push_back((TempNum + 2)*pow(2,Count) - pow(2,Count-1) - 1);
		}
	}
	return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/77885