#include<iostream>

using namespace std;

int solution(int n, int a, int b)
{

	a = (a + 1) / 2;
	b = (b + 1) / 2;
	if (a == b)
		return 1;
	else
		return solution(n / 2, a, b) + 1;
}
//https://programmers.co.kr/learn/courses/30/lessons/12985