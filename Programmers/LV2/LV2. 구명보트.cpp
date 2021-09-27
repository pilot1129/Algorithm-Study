#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
	int answer = 0, cnt = 0;
	sort(people.begin(), people.end());
	while (people.size() > cnt)
	{
		int last = people.back(); 
		people.pop_back();
		answer++;
		if (people[cnt] + last <= limit)
			cnt++;
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42885