#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
int solution(string name) 
{
    int answer = 0; 
    int len = name.length();
    int cnt = len-1;
    int next = 0;
    for(int i = 0; i<len; ++i)
    {
        answer += min(name[i] - 'A', 91- name[i]);
    }
 
    for(int i = 0; i < len; ++i) 
    {
        next = i + 1;
        while(next < len && name[next] == 'A') 
            next++;
        cnt = min(cnt, i + (len - next) + min(i, len - next));
    }
    answer += cnt;
 
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42860