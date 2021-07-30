#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> Onestr;
	vector<string> Twostr;
	vector<string> v_intersection;
	vector<string> v_union;
	int i;
	string temp;
	// »ðÀÔ
	for (i = 0; i < str1.length() - 1; ++i)
	{
		if (isalpha(str1[i]) != 0 && isalpha(str1[i + 1]) != 0)
		{
			temp = toupper(str1[i]);
			temp += toupper(str1[i + 1]);
			Onestr.push_back(temp);
		}
	}
	for (i = 0; i < str2.length() - 1; ++i)
	{
		if (isalpha(str2[i]) != 0 && isalpha(str2[i + 1]) != 0)
		{
			temp = toupper(str2[i]);
			temp += toupper(str2[i + 1]);
			Twostr.push_back(temp);
		}
	}
	sort(Onestr.begin(), Onestr.end());
	sort(Twostr.begin(), Twostr.end());
	set_intersection(Onestr.begin(), Onestr.end(), Twostr.begin(), Twostr.end(), back_inserter(v_intersection));
	set_union(Onestr.begin(), Onestr.end(), Twostr.begin(), Twostr.end(), back_inserter(v_union));
if (v_union.size() == 0)
		return 65536;
	float ans = (float)v_intersection.size() / (float)v_union.size() * 65536;
	return (int)ans;
}
//https://programmers.co.kr/learn/courses/30/lessons/17677