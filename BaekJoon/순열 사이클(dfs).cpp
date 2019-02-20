#include <iostream>
using namespace std;
int p[1001];
bool v[1001];
void dfs(int n)
{
	if (v[n] == true) return;
	if (v[n] == false) v[n] = true;
	dfs(p[n]);
	return;
}
int main()
{
	int T,N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> p[i];
			v[i] = false;
		}
		int res = 0;
		for (int i = 1; i <= N; i++) {
			if (v[i] == false) {
				dfs(i);
				res++;
			}
			else continue;
		}
		cout << res << endl;
	}
}