#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int i = 0;
    while(i != absolutes.size())
    {
        if(signs[i]) // true
            answer += absolutes[i];
        else
            answer -= absolutes[i];
        i++;
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/76501