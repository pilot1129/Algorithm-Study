#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool check_Balance(string a)
{
	int Check = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] == '(')
			++Check;
		else
			--Check;
		if (Check < 0)
			return false;
	}
	return true;
}

string Calculate(string a)
{
	if (a == "" || check_Balance(a)) return a;
	int Check = 0;
	string u = "";
	string v = "";
	string res = "";
	// u, v 분리
	for(int i = 0; i < a.length(); ++i)
	{
		if (a[i] == '(')
			++Check;
		else
			--Check;
		if (Check == 0)
		{
			u.append(a, 0, i+1);
			v.append(a, i + 1, a.length() - i);
			break;
		}
	}
	if (check_Balance(u)) // 올바르면
	{
		res = Calculate(v);
		return u + res;
	}
	else // 균
	{
		res += "("; // 1단계
		res += Calculate(v);// 2단계
		//res += v; 
		res += ")"; // 3단계
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.size(); ++i)
		{
			if (u[i] == '(')
				res += ")";
			else
				res += "(";
		}
		return res;
	}
}

string solution(string p) 
{
	return Calculate(p);
}
//https://programmers.co.kr/learn/courses/30/lessons/60058#