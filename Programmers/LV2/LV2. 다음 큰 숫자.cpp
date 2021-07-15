#include <string>
#include <vector>

using namespace std;

int CountOne(int num)
{
    int Count = 0;
    while(num > 0)
    {
        if(num%2)
            Count++;
        num /= 2;
    }
    return Count;
}

int solution(int n) {
    int answer = 0;
    int two = CountOne(n);
    int i = n+1;
    while(1)
    {
        if(CountOne(i) == two)
            return i;
        else
            i++;
    }
}
// https://programmers.co.kr/learn/courses/30/lessons/12911