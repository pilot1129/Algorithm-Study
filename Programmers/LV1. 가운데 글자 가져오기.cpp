#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0; i<s.size(); ++i)
    {
        int j = s.size()-1 - i;
        if(i == j)
        {
            answer = s[i];
            break;
        }
        else if(j == i+1)
        {
            answer += s[i];
            answer += s[j]; 
            break;
        }
    }
    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/12903