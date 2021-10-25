#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long solution(int n, vector<int> times) 
{
    long long answer;
    long long min = 1, max= 0, mid = 0, sum = 0;
    max = *max_element(times.begin(), times.end()) * (long long)n;
    answer = max;
 
    while (min <= max) 
    {
        sum = 0;
        mid = (min + max) / 2;
        for (auto t : times)
            sum += mid / t;
        
        if (sum < n)
            min = mid + 1;
        else 
        {
            max = mid - 1;
            answer = mid;
        }
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/43238