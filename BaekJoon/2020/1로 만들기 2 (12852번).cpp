#include <iostream>
#include <queue>
using namespace std;
pair<int, int> p[1000001];
int N;

void dynamic() {
	p[1] = { 0,0 };
	for (int i = 2; i <= N; i++) {
		p[i] = { p[i - 1].first + 1,i - 1 };
		if (i % 2 == 0) {
			if (p[i].first > p[i / 2].first + 1)
				p[i] = { p[i / 2].first + 1, i / 2 };
		}
		if (i % 3 == 0) {
			if (p[i].first > p[i / 3].first + 1)
				p[i] = { p[i / 3].first + 1, i / 3 };
		}
		if (p[i].first > p[i - 1].first + 1) {
			p[i] = { p[i - 1].first + 1,i - 1 };
		}
	}
}

int main()
{
	cin >> N;
	dynamic();
	cout << p[N].first << "\n";
	
	int i = N;
	cout << N << " ";
	while (p[i].second != 0) {
		cout << p[i].second << " ";
		i = p[i].second;
	}
}