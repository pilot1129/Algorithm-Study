#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    
    vector<int> temp;
    temp.assign(d.begin(), d.end());
    sort(temp.begin(), temp.end());
    for(int i = 0; i<temp.size(); ++i)
    {
        sum += temp[i];
        if(budget < sum)
            break;
        answer++;
    }
    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/12982