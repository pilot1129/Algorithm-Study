#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<float, int>& a, const pair<float, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

// N : 전체 스테이지수 
// stage : 사용자가 멈춘 스테이지 번호
// answer : 실패율이 높은 스테이지부터 내림차순
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, int>> sort_vec;
	int size = stages.size();
	int* fail_arr = new int[N + 1]; // 0 ~ N-1 stage
	float* new_arr = new float[N];

	// 1. init
	for (int i = 0; i < N; ++i)
		fail_arr[i] = 0;

	// 2. 성공 횟수 Plus 
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < stages[i] - 1; ++j)
		{
			fail_arr[j]++;
		}
	}
	new_arr[0] = (float)(size - fail_arr[0]) / (float)size;
	for (int i = 1; i < N; ++i)
	{
		if (fail_arr[i - 1] == 0)
		{
			new_arr[i] = 0;
			continue;
		}
		new_arr[i] = ((float)(fail_arr[i - 1] - fail_arr[i]) / (float)fail_arr[i - 1]);
	}

	// 3. 정렬
	for (int i = 0; i < N; ++i)
	{
		sort_vec.push_back(make_pair(new_arr[i], i));
	}
	sort(sort_vec.begin(), sort_vec.end(), comp);

	for (int i = 0; i < N; ++i)
	{
		answer.push_back(sort_vec[i].second+1);
	}


	delete[] fail_arr;
	delete[] new_arr;
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42889