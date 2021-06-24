#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
    if(a.first == b.first)
    {
        if(a.second.compare(b.second) < 0)
            return true;
        else 
            return false;
    }
    else
        return a.first < b.first;
        
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<int, string>> sorting;
    
    for(int i = 0; i<strings.size(); ++i)
    {
        sorting.push_back({(strings[i][n] - '0'),strings[i]});
    }
    sort(sorting.begin(), sorting.end(), cmp);
    
    for(int i = 0 ;i<sorting.size(); ++i)
    {
        answer.push_back(sorting[i].second);
    }
    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/12915