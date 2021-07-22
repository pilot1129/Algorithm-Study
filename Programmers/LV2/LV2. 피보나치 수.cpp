#include <string>
#include <vector>

using namespace std;

int solution(int i)
{
    int bef = 0;
    int cur = 1;
    int temp;
    if(i == 0)
        return 0;
    else if(i == 1)
        return 1;
    else
    {
        for(int loop = 1; loop < i; ++loop)
        {
            temp = cur % 1234567;
            cur = (bef + cur)%1234567;
            bef = temp % 1234567;
        }
        return cur % 1234567;
    }
}

//https://programmers.co.kr/learn/courses/30/lessons/12945