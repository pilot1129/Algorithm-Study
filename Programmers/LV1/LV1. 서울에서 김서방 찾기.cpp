#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    answer += to_string(find(seoul.begin(), seoul.end(), "Kim") - seoul.begin());
    answer += "에 있다";
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12919