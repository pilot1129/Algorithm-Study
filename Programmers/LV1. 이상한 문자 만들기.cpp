#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = 0;
    int i = 0;
    while(n < s.length())
    {
        int num = (int)s[n]; 
        if(num == 32)
        {
            answer += " ";
            i = 0;
        }
        else if(i%2)
        {
            answer += tolower(num);
            i++;
        }
        else
        {
            answer += toupper(num);
            i++;
        }
        n++;          
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12930