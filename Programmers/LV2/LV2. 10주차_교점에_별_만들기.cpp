#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<long, long> a, pair<long, long> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

pair<long, long> intersection(vector<int> v1, vector<int> v2)
{
	pair<long, long> temp;
	double parent = v1[0] * v2[1] - v1[1] * v2[0];
	
	if (parent == 0)
		temp = make_pair(1001, 1001);
	else
	{
		double childx = v1[1] * v2[2] - v1[2] * v2[1];
		double childy = v1[2] * v2[0] - v1[0] * v2[2];
		double x = childx / parent;
		double y = childy / parent;
		if (x == (long)x && y == (long)y)
			temp = make_pair(childx / parent, childy / parent);
		else
			//temp = make_pair(1000, 1000);
			temp = make_pair((long)1001, (long)1001);
	}
	return temp;
}
void sorting(vector<pair<long, long>>& v)
{
	sort(v.begin(), v.end(), comp);
	v.erase(unique(v.begin(), v.end()), v.end());
}

vector<string> solution(vector<vector<int>> line) 
{
	vector<string> answer;
	vector<pair<long, long>> pointlist;
	long maxX = 1001;
	long minX = 1001;
	long maxY = 1001;
	long minY = 1001;
	for (auto i = 0; i < line.size()-1; ++i)
	{
		for (auto j = i + 1; j < line.size(); ++j)
		{
			pair<long, long> temp = intersection(line[i], line[j]);
			if (temp.first != 1001)
			{
				if (maxX == 1001)
				{
					maxX = temp.first;
					minX = temp.first;
					maxY = temp.second;
					minY = temp.second;
				}
				else
				{
					maxX = max(maxX, temp.first);
					minX = min(minX, temp.first);
					maxY = max(maxY, temp.second);
					minY = min(minY, temp.second);
				}
				pointlist.push_back(temp);
			}
		}
	}
	sorting(pointlist);
	if (pointlist.empty())
		pointlist.push_back(make_pair(maxX, maxY));

	int cnt = 0;
	for (auto Y = maxY; Y >= minY; --Y)
	{
		string line = "";
		for (auto X = minX; X <= maxX; ++X)
		{
			if (X == pointlist[cnt].first && Y == pointlist[cnt].second)
			{
				line += "*";
				cnt++;
			}
			else
				line += ".";
		}
		answer.push_back(line);
	}

	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/87377