#include <string>
#include <cctype>
#include <iostream>
using namespace std;

// 1. 스타상* == * 2[해당 점수와 바로 전 점수를 2배]
// 2. 아차상 == * -1
// 3. s / d /t

int solution(string dartResult) {
	int answer = 0;
	int num = 0;
	int stagescore[3] = { 0, };
    int count = 0;
	for (int i = 0; i < dartResult.length(); ++i)
	{
		if (isdigit(dartResult[i]) != 0) // 숫자일 경우
		{
            if(isdigit(dartResult[i+1]) != 0) // 10인경우
                num += 10;
            else // 한자리수인경우
                num += dartResult[i] - '0';
		}
		else if (isalpha(dartResult[i]) != 0) // 알파벳의 경우
		{
            if(dartResult[i] == 'D')
                num *= num; 
            else if(dartResult[i] == 'T')
                num = num*num*num;
            stagescore[count] = num;
            count++;
            num = 0;
		}
		else // 옵션일 경우
		{
			if (dartResult[i] == '*')
			{
                if(count != 0) // 두번째나 세번째 별
                    stagescore[count-2] *= 2;
                stagescore[count-1] *= 2;
			}
			else // #의경우
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