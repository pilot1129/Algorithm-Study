#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) 
{
    unsigned int number = 2;
    while(number < sqrt(n))
    {
        if(n%number == 1)
            return number;
        number++;
    }
    return n-1;
}
//https://programmers.co.kr/learn/courses/30/lessons/87389