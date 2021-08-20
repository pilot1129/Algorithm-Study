#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	vector<int> Order1;
	for (auto i = 0; i < skill_trees.size(); ++i)
	{
		string CurStr = skill_trees[i];
		for (auto j = 0; j < skill.length(); ++j)
		{
			auto it = find(CurStr.begin(), CurStr.end(), skill[j]);
			if (it != CurStr.end())
				Order1.push_back(it - CurStr.begin());
			else
				Order1.push_back(27);
		}

		vector<int> Temp = Order1;
		sort(Temp.begin(), Temp.end());
		if (equal(Temp.begin(), Temp.end(), Order1.begin()))
			answer++;
		Order1.clear();

	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/49993