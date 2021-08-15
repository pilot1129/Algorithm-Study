#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool Check(int num)
{
	return (float)sqrt(num) == (int)sqrt(num);
}

vector<int> Quad(vector<vector<int>>&arr, int row, int col, int arrsize)
{
	vector<int> answer = { 0,0 };
	if(arrsize == 1)
		answer[arr[row][col]]++;
	else
	{
		vector<vector<int>> Sums;
		Sums.push_back(Quad(arr, row, col, arrsize / 2));
		Sums.push_back(Quad(arr, row , col + arrsize / 2, arrsize / 2));
		Sums.push_back(Quad(arr, row + arrsize / 2, col, arrsize / 2));
		Sums.push_back(Quad(arr, row + arrsize / 2, col + arrsize / 2, arrsize / 2));

		answer[0] = Sums[0][0] + Sums[1][0] + Sums[2][0] + Sums[3][0];
		answer[1] = Sums[0][1] + Sums[1][1] + Sums[2][1] + Sums[3][1];


		if (answer[0] == 4 && answer[1] == 0)
			answer[0] = 1;
		else if (answer[1] == 4 && answer[0] == 0)
			answer[1] = 1;
	}
	return answer;
}

vector<int> solution(vector<vector<int>> arr)
{
	vector<int> answer = { 0,0 };
	answer = Quad(arr, 0, 0, arr.size());
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/68936#