#include<iostream>
#include<vector>
using namespace std;

//Recursion
void dfs(int start, vector<int> graph[], bool check[])
{
	check[start] = true;
	int next_node = 0;
	for (int i = 0; i < graph[start].size(); ++i)
	{
		next_node = graph[start][i];
		/*
			* 수행해야 하는 기능을 이곳에 작성
		*/

		if (!check[next_node])//미방문시
			dfs(next_node, graph, check);
	}
}
		
//Non-Recursion
void dfs_vector(int start, vector<int> graph[], bool check[])
{
	vector<int> history;
	history.push_back(start);
	check[start] = true;
	int cur_node = 0;
	int next_node = 0;

	while (!history.empty())
	{
		cur_node = history.back();
		history.pop_back();
		for (int i = 0; i < graph[cur_node].size(); ++i)
		{
			next_node = graph[cur_node][i];
			/*
				* 수행해야 하는 기능을 이곳에 작성
			*/
			if (!check[next_node])
			{
				check[next_node] = true;
				history.push_back(cur_node);
				history.push_back(next_node);
				break;
			}
		}
	}
}
