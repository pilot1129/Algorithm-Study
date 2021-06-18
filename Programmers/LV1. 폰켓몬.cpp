#include <vector>
#include<unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int,int> Check_poncketmon;
    for(int i = 0; i < nums.size(); ++i)
    {
        Check_poncketmon.insert(make_pair(nums[i],0));
    }
    if(Check_poncketmon.size() >= (nums.size()/2))
        answer = (nums.size()/2);
    else
        answer = Check_poncketmon.size();
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/1845