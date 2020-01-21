#include <iostream>
using namespace std;
int p[15];
int s[4]; // +,-,x,/ÀÇ °³¼ö
int N,min_res= 1000000001, max_res= -1000000001;
void dfs(int idx, int sum)
{
	if (idx == N) {
		if (max_res < sum) max_res = sum;
		if (min_res > sum) min_res = sum;
		return;
	}
	if (s[0] > 0) {
		s[0]--;
		dfs(idx + 1, sum + p[idx]);
		s[0]++;
	}
	if (s[1] > 0) {
		s[1]--;
		dfs(idx + 1, sum - p[idx]);
		s[1]++;
	}
	if (s[2] > 0) {
		s[2]--;
		dfs(idx + 1, sum * p[idx]);
		s[2]++;
	}
	if (s[3] > 0) {
		s[3]--;
		dfs(idx + 1, sum / p[idx]);
		s[3]++;
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i];
	for (int i = 0; i < 4; i++) cin >> s[i];
	dfs(1,p[0]);
	cout << max_res << "\n" << min_res;
}