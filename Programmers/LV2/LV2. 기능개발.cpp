#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Progress;
    int process = 0;
    int todayprocess;
    int i = 0;
    bool popcheck, todaycheck;
    
    for(int i = 0; i<progresses.size(); ++i)
    {
        Progress.push(progresses[i]);
    }
    
    while(!Progress.empty())
    {
        todayprocess = 0;
        popcheck = false;
        todaycheck = false;
        for(i = process; i<progresses.size(); ++i)
        {
            int cur = Progress.front() + speeds[i];
            if(cur > 99)
            {
                if(i == process)
                {
                    popcheck = true;
                    todaycheck = true;
                    todayprocess++;
                }
                else if(popcheck)
                    todayprocess++;
                else
                    Progress.push(cur);
            }
            else
            {
                popcheck = false;
                Progress.push(cur);
            }
            Progress.pop();
        }
        if(todaycheck)
            answer.push_back(todayprocess);
        process += todayprocess;
    }
    
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42586