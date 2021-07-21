#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp;
    int curtemp = 0;
    
    for(int l1 = 0; l1<arr1.size(); ++l1)
    {
        for(int r1 = 0; r1<arr2[0].size(); ++r1)
        {
            for(int lr2 = 0; lr2<arr2.size(); ++lr2)
            {
                curtemp += arr1[l1][lr2] * arr2[lr2][r1];
            }
            temp.push_back(curtemp);
            curtemp = 0;
        }
        answer.push_back(temp);
        temp.clear();
    }
    
    
    return answer;
}
// https://programmers.co.kr/learn/courses/30/lessons/12949#