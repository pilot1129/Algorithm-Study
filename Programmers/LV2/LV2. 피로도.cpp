#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;
bool cmp(vector<int> first, vector<int> second)
{
	return first[0] > second[0];
}

void DFS(vector<vector<int>>& dungeons, vector<bool>& visit, int cur, int fatigue, int depth)
{
	visit[cur] = true;
	fatigue -= dungeons[cur][1];
	depth++;
	for (auto i = 0; i < dungeons.size(); ++i)
	{
		if (!visit[i] && dungeons[i][0] <= fatigue)
			DFS(dungeons, visit, i, fatigue, depth);
	}
	visit[cur] = false;
	answer = max(answer, depth);
}

int solution(int k, vector<vector<int>> dungeons)
{
	sort(dungeons.begin(), dungeons.end(), cmp);
	vector<bool> visit(dungeons.size());
	for (auto i = 0; i < dungeons.size(); ++i)
	{
		DFS(dungeons, visit, i, k, 0);
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/87946