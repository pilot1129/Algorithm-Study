#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size()-1 ;++i)
	{
		string temp = phone_book[i];
		if(temp == phone_book[i+1].substr(0,temp.length()))
			return false;
	}

	return true;
}
// https://programmers.co.kr/learn/courses/30/lessons/42577