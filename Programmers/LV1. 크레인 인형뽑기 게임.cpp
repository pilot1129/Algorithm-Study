#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> Bucket; // ������ ��� ���� ����
	const int width = board[0].size(); // ����
	const int height = board.size(); // ����
	int* arr = new int[width];// ���� ��ĭ ������
	for (int i = 0; i < width; ++i)
		arr[i] = height; // �ְ�+1�� �ʱ�ȭ

	//1. arr ����
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (board[i][j] != 0 && arr[j] == height)
				arr[j] = i;
		}
	}

	//2. ����
	for (int i = 0; i < moves.size(); ++i)
	{
        int loc = moves[i]-1;
        int cur = arr[loc];
		if (cur == height) // �ƹ��͵� ���ٸ�
			continue;
		else // �ִٸ�
		{
            if(Bucket.empty()) // ��Ŷ�� ���������
                Bucket.push_back(board[cur][loc]);
			else if(Bucket.back() == board[cur][loc]) // �հŶ� ��ġ��
			{
				Bucket.pop_back();
				answer += 2;
			}
			else // �Ȱ�ġ��
				Bucket.push_back(board[cur][loc]);
			arr[loc]++;
		}
	}
	delete arr;

	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/64061