#include <iostream>
#include <algorithm>
using namespace std;
int N, r, c;
pair<int, int> p[4];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0, tmp; j < 3; j++) {
			cin >> tmp;
			p[j].first += tmp, p[j].second += tmp*tmp;
		}
	}
	if (p[1] > p[0]) r = 1;
	else if (p[1] == p[0]) c++;
	if (p[2] > p[r]) r = 2, c = 0;
	else if (p[2] == p[r]) c++;
	printf("%d %d", c ? 0 : r + 1, p[r].first);
	return 0;
}