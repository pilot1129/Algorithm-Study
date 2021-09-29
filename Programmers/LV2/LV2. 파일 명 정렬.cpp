#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& first, const string& second) 
{

	//글자
	string w_first = "";
	string w_second = "";
	int idx_first = 0;
	int idx_second = 0;
	while (idx_first < first.length())
	{
		if (first[idx_first] >= '0' && first[idx_first] <= '9')
			break;
		else 
		{
			w_first += tolower(first[idx_first]);
			idx_first++;
		}
	}
	while (idx_second < second.length()) 
	{
		if (second[idx_second] >= '0' && second[idx_second] <= '9')
			break;
		else 
		{
			w_second += tolower(second[idx_second]);
			idx_second++;
		}
	}

	if (w_first != w_second)
		return w_first < w_second;

	//숫자
	string n_first = "";
	string n_second = "";
	for (int i = 0; i < 5; ++i) 
	{
		if (idx_first == first.length())
			break;
		if (first[idx_first] >= '0' && first[idx_first] <= '9') 
		{
			n_first += first[idx_first];
			idx_first++;
		}
		else 
			break;
	}
	for (int i = 0; i < 5; ++i) 
	{
		if (idx_second == second.length())
			break;
		if (second[idx_second] >= '0' && second[idx_second] <= '9') 
		{
			n_second += second[idx_second];
			idx_second++;
		}
		else 
			break;
	}
	if (stoi(n_first) != stoi(n_second))
		return stoi(n_first) < stoi(n_second);
}

vector<string> solution(vector<string> files) 
{
	vector<string> answer = files;
	stable_sort(answer.begin(), answer.end(), cmp);
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/17686