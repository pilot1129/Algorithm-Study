#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool calc(string a, string b)
{
	return a + b > b + a;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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