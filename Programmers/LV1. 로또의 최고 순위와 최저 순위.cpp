#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int correspond = 0;
    int zero = 0;
    for(int i = 0; i<6; ++i)
    {
        for(int j = 0; j<6; ++j)
        {
            if(lottos[j] == 0 && i == 0) // 0의 경우(한번만 셀 수 있도록)
                zero++;
            else if(lottos[j] == win_nums[i]) // 일치하는 것의 경우
                correspond++;
        }
    }
    if(correspond > 0) // 하나라도 맞은 경우
    {
        answer.push_back(7-(correspond+zero));
        answer.push_back(7-correspond);
    }
    else if(zero == 6) //하나도 맞지 않고, 전부 0인 경우
    {
        answer.push_back(1);
        answer.push_back(6);
    }
    else if(zero == 0) // 하나도 맞지 않고, 0도 없는 경우
    {
        answer.push_back(6);
        answer.push_back(6);
    }
    else // 하나도 맞지 않고, 0이 1개 이상인 경우
    {
        answer.push_back(7-(correspond+zero));
        answer.push_back(6);
    }

    return answer;
}

/*
	문항 : https://programmers.co.kr/learn/courses/30/lessons/77484

*/