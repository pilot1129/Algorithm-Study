#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); ++i)
    {
        vector<int> command_result;
        for(int j = commands[i][0] -1; j<commands[i][1]; ++j)
        {
            command_result.push_back(array[j]);
        }
        sort(command_result.begin(), command_result.end());
        answer.push_back(command_result[(commands[i][2])-1]);
    }
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42748