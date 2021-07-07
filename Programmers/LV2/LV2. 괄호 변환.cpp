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
	// u, v �и�
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
	if (check_Balance(u)) // �ùٸ���
	{
		res = Calculate(v);
		return u + res;
	}
	else // ��
	{
		res += "("; // 1�ܰ�
		res += Calculate(v);// 2�ܰ�
		//res += v; 
		res += ")"; // 3�ܰ�
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