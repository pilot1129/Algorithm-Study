#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n != 0)
    {
        ans += n%2;
        n /=2;
    }

    return ans;
}
//https://programmers.co.kr/learn/courses/30/lessons/12980