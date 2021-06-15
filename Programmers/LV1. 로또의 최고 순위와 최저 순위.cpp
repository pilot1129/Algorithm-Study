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
            if(lottos[j] == 0 && i == 0) // 0�� ���(�ѹ��� �� �� �ֵ���)
                zero++;
            else if(lottos[j] == win_nums[i]) // ��ġ�ϴ� ���� ���
                correspond++;
        }
    }
    if(correspond > 0) // �ϳ��� ���� ���
    {
        answer.push_back(7-(correspond+zero));
        answer.push_back(7-correspond);
    }
    else if(zero == 6) //�ϳ��� ���� �ʰ�, ���� 0�� ���
    {
        answer.push_back(1);
        answer.push_back(6);
    }
    else if(zero == 0) // �ϳ��� ���� �ʰ�, 0�� ���� ���
    {
        answer.push_back(6);
        answer.push_back(6);
    }
    else // �ϳ��� ���� �ʰ�, 0�� 1�� �̻��� ���
    {
        answer.push_back(7-(correspond+zero));
        answer.push_back(6);
    }

    return answer;
}

/*
	���� : https://programmers.co.kr/learn/courses/30/lessons/77484

*/