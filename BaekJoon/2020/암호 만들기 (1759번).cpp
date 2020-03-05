#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
char p[16];

void dfs(int cur, string str, int mo, int ja) {
	if (cur > C) return;
	if (str.size() == L) {
		if (mo < 1 || ja < 2) return;
		else cout << str << "\n";
		return;
	}
	if (p[cur] == 'a' || p[cur] == 'e' || p[cur] == 'i' || p[cur] == 'o' || p[cur] == 'u') 
		dfs(cur + 1, str + p[cur], mo + 1, ja);
	else
		dfs(cur + 1, str + p[cur], mo, ja + 1);
	dfs(cur + 1, str, mo, ja);
}
int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> p[i];
	sort(p, p + C);

	dfs(0, "", 0, 0);

	return 0;
}
