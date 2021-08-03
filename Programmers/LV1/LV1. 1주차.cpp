#include <cmath>

using namespace std;

long long solution(int price, int money, int count)
{
    long long cost = ((1+count)*count/2);
    cost *= price;
    return (money-cost) < 0? abs(money-cost) : 0;
}
// https://programmers.co.kr/learn/courses/30/lessons/82612/solution_groups?language=cpp