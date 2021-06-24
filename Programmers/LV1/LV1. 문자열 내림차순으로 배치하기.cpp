#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> answerv;
    for(int i = 0; i<s.size(); ++i)
        answerv.push_back((int)s[i]);
    sort(answerv.begin(), answerv.end(), greater<>());
    for(int i = 0; i<answerv.size(); ++i)
        answer += (char)answerv[i];
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12917