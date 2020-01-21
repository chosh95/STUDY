#include <iostream>
using namespace std;
int p[1001];
int main()
{
	for (int i = 1; i <= 1000; i++) p[i] = 1;

	int N, K, count = 0;
	cin >> N >> K;
	for (int i = 2; i <= 1000; i++) {
		if (p[i] == 0) continue;
		for (int j = i; j <= N; j += i) {
			if (p[j] != 0){
				p[j] = 0;
				++count;
				if (count == K) {
					cout << j;
					return 0;
				}
			}
		}
	}
}
