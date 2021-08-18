#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char ScoreCheck(int score)
{
	if (score >= 90)
		return 'A';
	else if (score >= 80)
		return 'B';
	else if (score >= 70)
		return 'C';
	else if (score >= 50)
		return 'D';
	else
		return 'F';
}

string solution(vector<vector<int>> scores)
{
	string answer = "";
	unsigned int VECTORSIZE = scores.size();
	for (unsigned int col = 0; col < VECTORSIZE; ++col)
	{
		vector<int> StudentScore;
		unsigned int Sum = 0;
		for (unsigned int row = 0; row < VECTORSIZE; ++row)
		{
			StudentScore.push_back(scores[row][col]);
			Sum += scores[row][col];
		}
		sort(StudentScore.begin(), StudentScore.end());
		if (StudentScore[0] == scores[col][col])
		{
			if (StudentScore[0] != StudentScore[1])
				answer += ScoreCheck((Sum - scores[col][col]) / (VECTORSIZE - 1));
			else
				answer += ScoreCheck(Sum / VECTORSIZE);
		}
		else if (StudentScore[VECTORSIZE - 1] == scores[col][col])
		{
			if (StudentScore[VECTORSIZE - 1] != StudentScore[VECTORSIZE - 2])
				answer += ScoreCheck((Sum - scores[col][col]) / (VECTORSIZE-1));
			else
				answer += ScoreCheck(Sum / VECTORSIZE);
		}
		else
		{
			answer += ScoreCheck(Sum / VECTORSIZE);
		}
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/83201