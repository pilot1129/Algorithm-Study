#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool check_odd(int num) // true = ¦�� , false = Ȧ��
{
    bool find = true;
    for(int i = 1; i<=num; ++i)
    {
        if(num % i == 0)
            find = !find;
    }
    return find;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i<=right; ++i)
    {
        if(check_odd(i))
            answer += i;
        else
            answer -= i;
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/77884