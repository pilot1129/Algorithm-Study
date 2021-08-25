#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> Pyram;

	Pyram.resize(n);
	for (auto i = 0; i < n; ++i)
	{
		Pyram[i].resize(n);
	}
	
	unsigned int check = 0;
	unsigned int number = 1;
	for (auto i = n; i > 0; i--)
	{
		unsigned int Index = check / 3;
		if (check%3 == 0)//6 3 
		{
			for (auto j = 0; j < i; ++j)
			{
				unsigned int x = j + Index * 2;
				unsigned int y = Index;
				Pyram[x][y] = number;
				number++;
			}
		}
		else if (check % 3 == 1) // 5 2
		{
			for (auto j = 0; j < i; ++j)
			{
				unsigned int x = n - Index - 1;
				unsigned int y = j + Index + 1;
				Pyram[x][y] = number;
				number++;
			}
		}
		else // 4 1
		{
			for (auto j = 0; j < i; ++j)
			{
				unsigned int x = n - j - Index- 2;
				unsigned int y = x - Index;
				Pyram[x][y] = number;
				number++;
			}
		}
		check++;
	}
	
	for (auto x = 0; x < n; ++x)
	{
		for (auto y = 0; y < x + 1; ++y)
		{
			answer.push_back(Pyram[x][y]);
		}
	}

	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/68645