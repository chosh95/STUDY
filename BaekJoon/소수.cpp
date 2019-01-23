#include <iostream>
using namespace std;

bool v[10001];

int main()
{
	int M, N;
	cin >> M >> N;
	for (int i = 1; i <= N; i++) v[i] = true;
	v[1] = false;
	for (int i = 2; i*i <= N; i++) {
		if (v[i] == false) continue;
		else {
			for (int j = i + i; j <= N; j += i) {
				v[j] = false;
			}
		}
	}
	int sum = 0;
	int min = 9999;
	for (int i = M; i <= N; i++) {
		if (v[i] == true) sum += i;
		if (v[i] == true && min > i) min = i;
	}
	if (sum == 0) cout << -1;
	else cout << sum << endl << min << endl;

}