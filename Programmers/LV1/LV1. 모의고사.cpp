#include <string>
#include <vector>

using namespace std;

// 1 : 12345
// 2 : 21232425
// 3 : 3311224455

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first[5] = {1,2,3,4,5};
    int second[8] = {2,1,2,3,2,4,2,5};
    int third[10] = {3,3,1,1,2,2,4,4,5,5};
    int cor[3] = {0,};
    
    for(int i =0; i<answers.size(); ++i)
    {
        if(first[i%5] == answers[i])
            cor[0]++;
        if(second[i%8] == answers[i])
            cor[1]++;
        if(third[i%10] == answers[i])
            cor[2]++;
    }
    int maxnum = cor[0];
    answer.push_back(1);
    for(int i = 1; i<3; ++i)
    {
        if(maxnum < cor[i])
        {
            while(!answer.empty())
                answer.pop_back();
            answer.push_back(i+1);
            maxnum = cor[i];
        }
        else if(maxnum == cor[i])
            answer.push_back(i+1);
    }
    
    
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42840/