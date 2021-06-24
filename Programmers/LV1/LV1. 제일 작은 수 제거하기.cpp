#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0];
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    for(int i = 1; i<arr.size(); ++i)
    {
        if(min > arr[i])
            min = arr[i];
    }
    arr.erase(find(arr.begin(), arr.end(), min));
    answer.assign(arr.begin(), arr.end());
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12935