#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int res = 0;
    int* arr = new int[n+1];
    for(int i = 2; i<n+1; ++i)
        arr[i] = i;
    
    for(int i = 2; i<sqrt(n); ++i)
    {
        if(arr[i] == 0)
            continue;
        for(int j = i*i; j<n+1; j += i)
            arr[j] = 0;
    }
    for(int i = 2; i<n+1; ++i)
    {
        if(arr[i] != 0)
            res++;
    }
    return res;
}
//https://programmers.co.kr/learn/courses/30/lessons/12921