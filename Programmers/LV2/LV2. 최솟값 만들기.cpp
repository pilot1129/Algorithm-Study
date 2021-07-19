#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end(), less<int>());
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < A.size(); ++i)
	{
		int temp = A[i] * B[i];
		answer += temp;
	}

	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12941