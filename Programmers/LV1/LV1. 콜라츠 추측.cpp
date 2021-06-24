#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long newnum = num;
    int answer = 0;
    while(newnum != 1)
    {
        if(answer == 501)
            return -1;
        newnum%2 ? newnum = newnum *3 + 1 : newnum /=2;
        answer++;
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12943