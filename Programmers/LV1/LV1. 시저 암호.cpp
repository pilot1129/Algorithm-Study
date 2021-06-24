#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    string little = "abcdefghijklmnopqrstuvwxyz";
    string big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i = 0; i<s.length(); ++i)
    {
        int num = (int)s[i];
        if(num == 32)
            answer += " ";
        else if(64 < num && num < 91)
        {
            num = ((num+n)-65)%26;
            answer += big[num];
        }
        else if(96 < num && num < 123)
        {
            num = ((num+n)-97)%26;
            answer += little[num];
        }
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12926