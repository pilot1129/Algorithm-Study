#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(s.size() == 4 || s.size() == 6)
    {
        return s.compare(to_string(atoi(s.c_str()))) == 0 ;
    }
    return false;
}
//https://programmers.co.kr/learn/courses/30/lessons/12918