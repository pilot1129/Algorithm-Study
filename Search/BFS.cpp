#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Non-Recursion
void bfs_queue(int start, vector<int> graph[], bool check[])
{
	queue<int> history;
	history.push(start);
	check[start] = true;
	int cur_node = 0;
	int next_node = 0;

	while (!history.empty())
	{
		cur_node = history.front();
		history.pop();
		for (int i = 0; i < graph[cur_node].size(); ++i)
		{
			next_node = graph[cur_node][i];
			/*
			* 수행해야 하는 기능을 이곳에 작성
			*/
			if (!check[next_node])
			{
				history.push(next_node);
				check[next_node] = true;
			}
		}
	}
}
