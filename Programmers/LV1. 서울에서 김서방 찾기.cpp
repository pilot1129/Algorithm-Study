#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";
    
    answer += to_string(find(seoul.begin(), seoul.end(), "Kim") - seoul.begin());
    answer += "�� �ִ�";
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12919