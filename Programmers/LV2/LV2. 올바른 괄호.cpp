#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int p = 0;
    for(int i = 0; i<s.length(); ++i)
    {
        if(s[i] == '(')
            ++p;
        else
            --p;
        if(p < 0)
            return false;
    }
    if(p>0)
        return false;
    else
        return true;
}