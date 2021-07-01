#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n)
{
    string answer = "";
    string arr[3] = { "1", "2", "4" };

    while (n!=0)
    {
        --n;
        answer = arr[n % 3] + answer;
        n /= 3;
    }

    return answer;
}