#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	string Temp = "";

	//LV1
	for (int i = 0; i < new_id.size(); ++i)
	{
		if ((int)new_id[i] >= 65 && (int)new_id[i] <= 90) // 대문자라면
			answer += (char)((int)new_id[i] + 32);
		else
			answer += new_id[i];
	}

	//LV2
	for (int i = 0; i < answer.size(); ++i)
	{
		if (((int)answer[i] >= 97 && (int)answer[i] <= 122) ||
			((int)answer[i] >= 48 && (int)answer[i] <= 57) ||
			answer[i] == '-' || answer[i] == '_' || answer[i] == '.')
			Temp += answer[i];
		else
			continue;
	}
	answer = "";
	answer += Temp[0];

	//LV3
	for (int i = 1; i < Temp.size(); ++i)
	{
		if (Temp[i - 1] == '.' && Temp[i] == '.')
			continue;
		else
			answer += Temp[i];
	}
	Temp = "";

	//LV4
	for (int i = 0; i < answer.size(); ++i)
	{
		if ((answer[0] == '.' && i==0) || (answer[answer.size() - 1] == '.' && i == answer.size()-1))
			continue;
		else
			Temp += answer[i];
	}
	answer = "";

	//LV5
	if (Temp == "")
		Temp = "a";

	//LV6
	for (int i = 0; i < 15; ++i)
	{
		if (Temp.size() == i)
			break;
		else if (i == 14 && Temp[i] == '.')
			break;
		else
			answer += Temp[i];
	}
	Temp = "";

	//LV7
	if (answer.size() < 3)
	{
        int size = answer.size();
		for (int i = 0; i < (3 - size); ++i)
		{
			answer += answer[size - 1];
		}
	}

	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/72410