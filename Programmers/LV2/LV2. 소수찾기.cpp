#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool Check_prime(int num)
{
	if (num == 1)
		return false;
	else if (num == 2)
		return true;
	int devnum = 2;
	while (1)
	{
		if (num % devnum == 0)
			return false; // 소수가 아니면
		if (devnum > sqrt(num))
			return true;
		devnum++;
	}
	return false; // error
}

void permutation(vector<int> num, int depth, int find, vector<int>& totalvec)
{
	if (depth == find)
	{
		int curnum = 0;
		int loop = 0;
		for (int i = 0; i < find; i++)
		{
			curnum += num[find-i-1] * pow(10, loop);
			loop++;
		}
		totalvec.push_back(curnum);
		return;
	}

	for (int i = depth; i < num.size(); i++)
	{
		iter_swap(num.begin() + depth, num.begin() + i);
		permutation(num, depth + 1, find, totalvec);  // ?재귀
		iter_swap(num.begin() + depth, num.begin() + i);  // 다시 원래 위치로 되돌리기
	}
}

int solution(string numbers) {
	vector<int> chars;
	int answer = 0;
	for (int i = 0; i < numbers.length(); ++i)
	{
		chars.push_back(numbers[i] - '0');
	}

	vector<int> Numbers;

	for (int i = chars.size(); i > 0; --i)
	{
		permutation(chars, 0, i, Numbers);
	}


	//중복 제거 및 소수판별
	sort(Numbers.begin(), Numbers.end());
	Numbers.erase(unique(Numbers.begin(), Numbers.end()), Numbers.end());
	for (int i = 0; i < Numbers.size(); ++i)
	{
		if(Check_prime(Numbers[i]))
			answer++;
	}

	return answer;
}

int main()
{
	solution("0123");
	return 0;
}
//https://programmers.co.kr/learn/courses/30/lessons/42839