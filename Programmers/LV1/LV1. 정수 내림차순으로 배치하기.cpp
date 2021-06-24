#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> nvec;
    while(n != 0)
    {
        nvec.push_back(n%10);
        n /= 10;
    }
    sort(nvec.begin(), nvec.end());
    for(int i = 0; i<nvec.size(); ++i)
    {
        answer += nvec[i]*pow(10,i);
    }
    
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12933