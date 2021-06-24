#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
	int number = n;
	string num_3 = "";
	// 1. 3���� ������
	while (number != 0)
	{
		int res = number % 3;
		num_3 += to_string(res);
		number -= res;
		number /= 3;
	}
	//2. string ��ȯ
	reverse(num_3.begin(), num_3.end());

	//10���� ��ȯ
	for (int i = num_3.size() - 1; i > -1; --i)
	{
        int p = pow(3,i);
		answer += (num_3[i] - '0') * p;
	}
    

	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/68935