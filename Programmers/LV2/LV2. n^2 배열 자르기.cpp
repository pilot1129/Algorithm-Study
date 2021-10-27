#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    while(left <= right)
    {
        int first = floor(left / n);
        int second = left % n;
        answer.push_back(max(first, second)+1);
        left++;
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/87390