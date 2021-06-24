#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string num = to_string(n);
    for(int j = num.size()-1; j> -1; --j)
    {
        answer.push_back(num[j] - '0');
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12932