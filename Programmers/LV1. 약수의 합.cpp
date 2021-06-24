#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 1;
    
    while(i <n+1)
    {
        if(n%i == 0)
            answer += i;
        ++i;
    }
    
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12928