#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> Bucket; // 뽑은걸 담기 위한 버켓
	const int width = board[0].size(); // 가로
	const int height = board.size(); // 세로
	int* arr = new int[width];// 제일 위칸 측정용
	for (int i = 0; i < width; ++i)
		arr[i] = height; // 최고+1로 초기화

	//1. arr 갱신
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (board[i][j] != 0 && arr[j] == height)
				arr[j] = i;
		}
	}

	//2. 삽입
	for (int i = 0; i < moves.size(); ++i)
	{
        int loc = moves[i]-1;
        int cur = arr[loc];
		if (cur == height) // 아무것도 없다면
			continue;
		else // 있다면
		{
            if(Bucket.empty()) // 버킷이 비어있으면
                Bucket.push_back(board[cur][loc]);
			else if(Bucket.back() == board[cur][loc]) // 앞거랑 겹치면
			{
				Bucket.pop_back();
				answer += 2;
			}
			else // 안겹치면
				Bucket.push_back(board[cur][loc]);
			arr[loc]++;
		}
	}
	delete arr;

	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/64061