#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool check_prime(int num)
{
    int devnum = 2;
    while(1)
    {
        if(num % devnum == 0)
            return false; // 소수가 아니면
        if(devnum > sqrt(num))
           return true;
        devnum++;
    }
    return false; // error
}
    
    
int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i = 0; i<nums.size()-2; ++i)
    {
        for(int j = i+1; j<nums.size()-1; ++j)
        {
            for(int k = j+1; k<nums.size(); ++k)
            {
                if(check_prime(nums[i] + nums[j] + nums[k]))
                    answer++;
            }
        }
    }
    return answer;
}

/*
https://programmers.co.kr/learn/courses/30/lessons/12977
*/