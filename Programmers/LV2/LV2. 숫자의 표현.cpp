#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int ans = 0;
	int AddNumber = 1;
	int Sum = 0;
	while (1)
	{
		Sum = 0;
		for (auto Comb = 1; Comb < AddNumber + 1; ++Comb)
		{
			Sum += Comb;
		}
		if (Sum > n)
			break;
		else if (((n - Sum) % AddNumber++) == 0)
		{
			ans++;
		}
	}
	return ans;
}
//https://programmers.co.kr/learn/courses/30/lessons/12924