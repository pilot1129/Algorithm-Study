#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0; i<scoville.size(); ++i)
        pq.push(scoville[i]);
 
    while (1) 
    {
        if(pq.size() == 1 || pq.top() >= K)
            break;
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    if (pq.top() < K)
        return -1;
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42626