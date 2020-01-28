#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

//canEat[i] : i번 친구가 먹을 수 있는 음식의 집합
//eater[i] : i번 음식을 먹을 수 있는 친구들의 집합
vector<int> canEat[50], eater[50];
int best; //결과값
int T, N, M;

void search(vector<int> edible, int chosen)
{
	if (best <= chosen) return;
	int first = 0;
	while (first < N && edible[first] != 0) first++;
	if (first == N) {
		best = chosen;
		return;
	}
	for (int i = 0; i < canEat[first].size(); i++) {
		int food = canEat[first][i];
		for (int j = 0; j < eater[food].size(); j++) 
			edible[eater[food][j]]++;
		search(edible, chosen + 1);
		for (int j = 0; j < eater[food].size(); j++)
			edible[eater[food][j]]--;
	}
}


int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> M;
		best = M;
		string tmp;
		map<string, int> index;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			index[tmp] = i; //tmp 이름을 가진 사람은 i번째 index를 가진다.
		}
		for (int tmpnum, i = 0; i < M; i++) {
			cin >> tmpnum;
			for (int j = 0; j < tmpnum; j++) {
				cin >> tmp;
				eater[i].push_back(index[tmp]);
				canEat[index[tmp]].push_back(i);
			}
		}

		vector<int> edible(N, 0);
		search(edible, 0);
		cout << best << endl;

		for (int i = 0; i < N; i++)
			canEat[i].clear();
		for (int i = 0; i < M; i++)
			eater[i].clear();
	}
}