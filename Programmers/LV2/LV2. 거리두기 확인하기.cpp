#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
// x = row , y = col

//T : ÀßÁöÅ´ , F : ¸øÁöÅ´
bool CheckPartition(int num, int a_x, int a_y, int b_x, int b_y, vector<vector<string>> places)
{
	if (a_x == b_x)
		return(places[num][a_x][(a_y + b_y) / 2] == 'X');
	else if (a_y == b_y)
		return(places[num][(a_x + b_x) / 2][a_y] == 'X');
	else
		return((places[num][a_x][b_y] == 'X') && (places[num][b_x][a_y] == 'X'));
}
int CheckDistance(int a_x, int a_y, int b_x, int b_y)
{
	int temp = abs(a_x - b_x) + abs(a_y - b_y);
	if (temp > 2)
		return 3;
	else
		return temp;
}


vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	vector<pair<int, int>> list;

	for (int i = 0; i < 5; ++i)
	{
		list.clear();
		bool check = true;
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				if (places[i][j][k] == 'P')
					list.push_back(make_pair(j, k));
			}
		}
		if (list.size() < 2)
			check = 1;
		else
		{
			for (int j = 0; j < list.size() - 1; ++j)
			{
				for (int k = j + 1; k < list.size(); ++k)
				{
					int distance = CheckDistance(list[j].first, list[j].second, list[k].first, list[k].second);
					if (distance > 2)
						continue;
					else if (distance == 2)
					{
						if (!CheckPartition(i, list[j].first, list[j].second, list[k].first, list[k].second, places))
							check = false;
					}
					else
						check = false;
					if (!check)
						break;
				}
				if (!check)
					break;
			}
		}
		answer.push_back(check);
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/81302