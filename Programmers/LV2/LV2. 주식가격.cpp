#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<pair<int,int>> numbers;
	vector<int> answer;
	answer.resize(prices.size());

	numbers.push_back(make_pair(prices[0],0));
	for (int i = 1; i < prices.size(); ++i)
	{
		if (numbers.back().first > prices[i])
		{
			while (numbers.back().first > prices[i])
			{
				int Loc = numbers.back().second;
				int Dif = i - Loc;
				answer[Loc] = Dif;
				numbers.pop_back();
				if (numbers.empty())
					break;
			}
		}
		numbers.push_back(make_pair(prices[i], i));
	}

	int Max = prices.size() - 1;
	int Size = numbers.size();
	for (int i = 0; i < Size; ++i)
	{
		int Loc = numbers.back().second;
		int Dif = Max - Loc;
		answer[Loc] = Dif;
		numbers.pop_back();
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42584#