#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int first, second;
    int maxelem = 0;
    int minelem = 0;
    for(auto i = 0; i<sizes.size(); ++i)
    {
        first = max(sizes[i][0],sizes[i][1]);
        second = min(sizes[i][0],sizes[i][1]);
        maxelem = max(first, maxelem);
        minelem = max(second, minelem);
    }
    return maxelem * minelem;
}
//https://programmers.co.kr/learn/courses/30/lessons/86491