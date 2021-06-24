#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max = 1;
    for(int i = 2; i<=min(n,m); ++i)
    {
        if(!((n%i) || (m%i)))
           max = i;
    }
    answer.push_back(max);
    answer.push_back(n*m/max);
    
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12940