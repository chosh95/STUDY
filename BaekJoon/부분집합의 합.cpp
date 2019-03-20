#include <iostream>
using namespace std;
int p[21];
int N, S, c;

void dfs(int i, int sum)
{
	
	if (i >= N) return;
	if (sum == S && i==N-1) c++;
	
	dfs(i + 1, sum + p[i + 1]);
	dfs(i + 1, sum);

}
int main()
{
	cin >> N >> S;
	c = 0;
	for (int i = 0; i < N; i++) cin >> p[i];
	dfs(-1, 0);
	if (S == 0) c--;
	cout << c;
}