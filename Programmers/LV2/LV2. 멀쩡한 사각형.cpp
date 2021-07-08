#include<iostream>
#include<algorithm>
using namespace std;

long long GCD(long long a, long long b)
{
	long long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long Calc(long long a, long long b)
{
	long long gcd = GCD(a, b);
	long long a_dev = a / gcd;
	long long b_dev = b / gcd;

	long long Empty = a_dev + b_dev - 1;
	long long res = a * b - gcd * (Empty);
	return res;
}

long long solution(int w, int h) {
	long long answer = 1;
	return Calc((long long)w,(long long)h);
}
//https://programmers.co.kr/learn/courses/30/lessons/62048