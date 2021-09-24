#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_elem(vector<int>& v, int cnt)
{
	int temp = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i != cnt)
			temp = max(v[i], temp);
	}
	return temp;
}

int solution(vector<vector<int>> land)
{
	int answer = 0;
	for (auto i = 1; i < land.size(); ++i) 
	{
		for (auto j = 0; j < 4; ++j) 
		{
			land[i][j] += max_elem(land[i - 1], j);
			answer = max(land[i][j], answer);
		}
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12913