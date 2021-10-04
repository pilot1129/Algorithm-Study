#include <string>
#include <vector>

using namespace std;

void calc(vector<int> numbers, int target, int sum, int cnt, int& ans) 
{
    if(cnt == numbers.size()) 
    {   
        if(sum == target) 
            ans++;
        return;
    }
    calc(numbers, target, sum+numbers[cnt], cnt+1, ans);
    calc(numbers, target, sum-numbers[cnt], cnt+1, ans);
}
int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    calc(numbers, target, 0, 0, answer);
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/43165