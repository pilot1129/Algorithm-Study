#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool calc(string a, string b)
{
	return a + b > b + a;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> stringnumbers;

	for (auto elem : numbers)
		stringnumbers.push_back(to_string(elem));

	sort(stringnumbers.begin(), stringnumbers.end(), calc);

	if (stringnumbers[0] == "0")
		return "0";

	for (auto elem : stringnumbers)
		answer += elem;
	return answer;
}