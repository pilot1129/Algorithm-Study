#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
	vector<int> prime;
	prime.push_back(2);
	for (int i = 3; i <= n; ++i)
	{
		bool check = true;
		for (int i = 0; i < prime.size(); ++i)
		{
			if (i%prime[i] == 0)
			{
				check = false;
				break;
			}
		}
		if (check)
			prime.push_back(i);
	}
	return prime.size();
}

int main()
{
	solution(10);
}