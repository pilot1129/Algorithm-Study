#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


void check(int arr[], int number)
{
    arr[0] = (number-1)/3;
    arr[1] = (number-1)%3;
}

void copyFunc(int arr1[], int arr2[])
{   
    arr1[0] = arr2[0];
    arr1[1] = arr2[1];
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int loc[2] = {0,0};
    int lefthand[2] = {3,0};
    int righthand[2]= {3,2};
    int loop = 0;
    int newnum = 0;

   while(loop != numbers.size())
   {
       newnum = numbers[loop];
       if(newnum == 0)
           newnum = 11;
       check(loc, newnum);
       if(loc[1] == 0)
       {
           answer += "L";
           copyFunc(lefthand, loc);
       }
       else if(loc[1] == 2)
       {
           answer += "R";
           copyFunc(righthand, loc);
       }
       else // Áß¾Ó°Íµé
       {
           int dif_left = abs(loc[0] - lefthand[0]) + abs(loc[1] - lefthand[1]); 
           int dif_right = abs(loc[0] - righthand[0]) + abs(loc[1] - righthand[1]); 
           if(dif_left > dif_right)
           {
                answer += "R";
                copyFunc(righthand, loc);
           }
           else if(dif_left < dif_right)
           {
                answer += "L";
                 copyFunc(lefthand, loc);
           }
           else
           {
               if(hand == "left")
               {
                   answer += "L";
                 copyFunc(lefthand, loc);
               }
               else
               {
                   answer += "R";
                copyFunc(righthand, loc);
               }
           }
       }
       
       loop++;
   }
    return answer;
}