#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    if((float)((int)sqrt(n)) == (float)sqrt(n))
        answer = pow(sqrt(n)+1,2);
    else
        answer = -1;
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12934