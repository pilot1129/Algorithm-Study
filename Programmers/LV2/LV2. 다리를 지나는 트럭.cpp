#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sum = 0;
	int count = 0;
	queue<int> trucks;
	while (1)
	{
		if (count == truck_weights.size())
		{
			answer += bridge_length;
			break;
		}
		int Truck = truck_weights[count];
		if (trucks.size() == bridge_length)
		{
			sum -= trucks.front();
			trucks.pop();
		}
		if (sum <= weight - Truck)
		{
			trucks.push(Truck);
			sum += Truck;
			count++;
		}
		else
			trucks.push(0);
		answer++;
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42583