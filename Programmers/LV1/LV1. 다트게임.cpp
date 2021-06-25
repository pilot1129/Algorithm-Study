#include <string>
#include <cctype>
#include <iostream>
using namespace std;

// 1. ��Ÿ��* == * 2[�ش� ������ �ٷ� �� ������ 2��]
// 2. ������ == * -1
// 3. s / d /t

int solution(string dartResult) {
	int answer = 0;
	int num = 0;
	int stagescore[3] = { 0, };
    int count = 0;
	for (int i = 0; i < dartResult.length(); ++i)
	{
		if (isdigit(dartResult[i]) != 0) // ������ ���
		{
            if(isdigit(dartResult[i+1]) != 0) // 10�ΰ��
                num += 10;
            else // ���ڸ����ΰ��
                num += dartResult[i] - '0';
		}
		else if (isalpha(dartResult[i]) != 0) // ���ĺ��� ���
		{
            if(dartResult[i] == 'D')
                num *= num; 
            else if(dartResult[i] == 'T')
                num = num*num*num;
            stagescore[count] = num;
            count++;
            num = 0;
		}
		else // �ɼ��� ���
		{
			if (dartResult[i] == '*')
			{
                if(count != 0) // �ι�°�� ����° ��
                    stagescore[count-2] *= 2;
                stagescore[count-1] *= 2;
			}
			else // #�ǰ��
                stagescore[count-1] *= -1;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		answer += stagescore[i];
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/17682