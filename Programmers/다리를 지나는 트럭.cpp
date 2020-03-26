#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int len, int weight, vector<int> truck) {
	int answer = 0; //시간
	int curWeight = 0; //현재 다리 위에 있는 트럭 무게
	int idx = 0; //트럭 인덱스
	queue<int> q; //다리 위에 있는 트럭 list
	while (1) {
		answer++;
		if (q.size() == len) { //트럭이 도착하면 무게 빼주고 제거
			curWeight -= q.front();
			q.pop();
		}
		if (curWeight + truck[idx] <= weight) { //트럭 추가할 수 있으면 추가
			if (idx == truck.size() - 1) { //마지막 트럭인 경우 
				answer += len;
				break;
			}
			q.push(truck[idx]);
			curWeight += truck[idx];
			idx++;
		}
		else {
			q.push(0); //트럭을 더 못 올리면 0으로 트럭 밀어주기
		}
	}
	return answer;
}

int main()
{
	cout << solution(2, 10, { 7,4,5,6 });
}