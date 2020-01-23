#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int T, N, p[1001];
int res;
int visit[1001];
void cycle(int n)
{
	if (visit[n] == 1) return;
	if (visit[n] == -1) visit[n] = 1;
	cycle(p[n]);
	return;
}
int main()
{
	cin >> T;
	while (T--) {
		cin >> N;
		memset(visit, -1, sizeof(visit));
		for (int i = 1; i <= N; i++) cin >> p[i];
		res = 0;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == -1) {
				res++;
				cycle(i);
			}
		}
		cout << res << "\n";
	}
}