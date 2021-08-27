#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) 
{
	vector<int> answer;
	map<string, vector<int>> InfoMap;

	for (auto i = 0; i < info.size(); ++i) 
	{
		string Temp;
		stringstream ss(info[i]);
		vector<vector<string>> str(4, vector<string>(2, "-"));
		int index = 0, score = 0;

		while (ss >> Temp) 
		{
			if (index < 4) 
				str[index++][0] = Temp;
			else
				score = stoi(Temp);
		}

		for (auto i = 0; i < 2; ++i) 
		{
			string t1, t2, t3, t4;
			t1 = str[0][i];
			for (auto j = 0; j < 2; ++j) 
			{
				t2 = str[1][j];
				for (auto k = 0; k < 2; ++k) 
				{
					t3 = str[2][k];
					for (auto l = 0; l < 2; ++l) 
					{
						t4 = str[3][l];
						InfoMap[t1 + t2 + t3 + t4].push_back(score);
					}
				}
			}
		}
	}

	for (auto itr = InfoMap.begin(); itr != InfoMap.end(); ++itr)
		sort(itr->second.begin(), itr->second.end());

	for (auto i = 0; i < query.size(); ++i) 
	{
		string str = "", Temp;
		stringstream ss(query[i]);
		int index = 0, score = 0;

		while (ss >> Temp) 
		{
			if (Temp == "and") 
				continue;
			if (index++ < 4)
				str += Temp;
			else 
				score = stoi(Temp);
		}

		auto itr = lower_bound(InfoMap[str].begin(), InfoMap[str].end(), score);
		answer.push_back(InfoMap[str].size() - (itr - InfoMap[str].begin()));
	}

	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/72412