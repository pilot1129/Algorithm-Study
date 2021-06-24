#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> answer_int;
    
    for(int i = 0; i<n; ++i)
    {
        int num = arr1[i] | arr2[i];
        string cur = "";
        int j = 0;
        while(j < n)
        {
            if(num%2)
                cur += "#";
            else
                cur += " ";
            num /= 2;
            j++;
        }
        reverse(cur.begin(), cur.end());
        answer.push_back(cur);
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/17681