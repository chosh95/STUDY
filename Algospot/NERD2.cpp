#include <iostream>
#include <map>
using namespace std;
int C, N;
map<int, int> coords;

bool isDominated(int x, int y) {
	map<int,int>::iterator it = coords.lower_bound(x); // 이 점의 바로 오른쪽 좌표
	if (it == coords.end()) return false; // 이 점보다 오른쪽에 있는 게 없으면 지배받을 수 없다.
	if (y < it->second) return true; // x, y 둘다 작으면 지배받는다.
	else return false;
}

void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x); //바로 오른쪽 좌표
	if (it == coords.begin()) return; //제거할 게 없다.
	--it;
	while (true) { //it은 항상 바로 왼쪽 좌표
		if (it->second > y) break; //지배받지 않으므로 탈출
		if (it == coords.begin()) { //지배받는 왼쪽점이 시작점이면 제거하고 탈출
			coords.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it; //왼쪽 좌표를 제거하고 하나 땡겨준다.
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}
int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size(); //지배당하면 추가하지말고 반환
	removeDominated(x, y); // 기존의 점 중에 지배당하는걸 제거
	coords[x] = y; //좌표 추가
	return coords.size();
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		coords.clear();
		int res = 0;
		for (int x, y, i = 0; i < N; i++) {
			cin >> x >> y;
			res += registered(x, y);
		}
		cout << res << endl;
	}
}