#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string temp = to_string(x);
    int sum = 0;
    for(int i = 0; i<temp.length(); ++i)
    {
        sum += temp[i] - '0';
    }
    return x%sum == 0;
}
//https://programmers.co.kr/learn/courses/30/lessons/12947