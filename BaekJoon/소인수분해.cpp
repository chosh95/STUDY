#include <iostream>
using namespace std;
bool p[10000000 + 1];
int main()
{
	int N,tmp,idx=2;
	cin >> N;
	tmp = N;
	for (int i = 1; i <= N; i++) p[i] = true;
	p[1] = false;
	for (int i = 2; i*i <= N; i++) {
		if (!p[i]) continue;
		for (int j = i + i; j <= N; j += i) {
			p[j] = false;
		}
	}
	while (true)
	{
		if (tmp == 1) return 0;
		if (idx == tmp) {
			cout << idx;
			return 0;
		}
		if (p[idx] && tmp%idx == 0) {
			tmp /= idx;
			cout << idx << endl;
		}
		else idx++;		
	}
}