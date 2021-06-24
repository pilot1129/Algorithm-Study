#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 0; i<n; ++i)
        i%2 == 0 ? answer+="¼ö" : answer+="¹Ú";
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12922