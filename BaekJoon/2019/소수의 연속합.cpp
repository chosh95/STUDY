#include <iostream>
#include <memory.h>
using namespace std;
bool p[4000001];
int N, res;

int main()
{
	memset(p, true, sizeof(p));
	cin >> N;
	p[1] = false;
	for (int i = 2; i*i <= 4000000; i++) {
		if (p[i]==false) continue;
		for (int j = i+i; j <= 4000000; j += i) {
			p[j] = false;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (p[i] == false) continue;
		int sum = 0;
		for (int j = i; j <= N; j++) {
			if (p[j] == false) continue;
			sum += j;
			if (sum == N) {
				res++;
				break;
			}
			else if (sum > N) {
				break;
			}
		}
	}
	cout << res;
}