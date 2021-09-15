#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int square = brown + yellow;
    int h = 3;
    while(1)
    {
        if((square % h) == 0)
        {
            int w = square / h;
            if(((h-2)*(w-2))==yellow)
            {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
               
        }
        h++;
    }
    return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42842