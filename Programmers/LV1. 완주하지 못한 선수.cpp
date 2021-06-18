#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string,int> completion_list;
    for(int i = 0; i<completion.size(); ++i)
    {
        if(completion_list.find(completion[i]) == completion_list.end())
            completion_list.insert(make_pair(completion[i],1));
        else
            completion_list[completion[i]]++;
    }
    
    for(int i = 0; i<completion.size(); ++i)
    {
        for(int j = 0; j<participant.size(); ++j)
        {
            if(completion_list.find(participant[j]) != completion_list.end())
            {
                if(completion_list[participant[j]] != 0)
                    completion_list[participant[j]]--;
                else
                {
                    answer = participant[j];
                    return answer;
                }
            }
            else
            {
                answer = participant[j];
                return answer;
            }
        }
    }
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/42576