#include <iostream>
#include <list>
using namespace std;
int C, N, K;

void josephus()
{
	list<int> survivor;
	for (int i = 1; i <= N; i++) survivor.push_back(i);
	list<int>::iterator kill = survivor.begin();
	while (N > 2) {
		kill = survivor.erase(kill);
		if (kill == survivor.end()) kill = survivor.begin();
		--N;
		for (int i = 0; i < K - 1; i++) {
			kill++;
			if (kill == survivor.end()) kill = survivor.begin();
		}
	}
	cout << survivor.front() << " " << survivor.back() << endl;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> K;
		josephus();
	}
}