#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0;
    int y = 0;
    for(int i= 0; i<s.size(); ++i)
    {
        int num = (int)s[i];
        if(num == 80 || num == 112)
            p++;
        if(num == 89 || num == 121)
            y++;
    }
    return p == y;
}
//https://programmers.co.kr/learn/courses/30/lessons/12916