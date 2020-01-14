#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int C, N, W;
int volume[102], need[102];
int dp[1002][102]; // 무게가 i일때 j번 아이템 이후에서 얻을 수 있는 절박도 
string name[102];
vector<string> ans;

int pack(int v, int item)
{
	if (item == N + 1) return 0;
	int& res = dp[v][item];
	if (res != -1) return res;
	res = pack(v, item + 1);
	if (v >= volume[item]) {
		res = max(res, pack(v - volume[item], item + 1) + need[item]);
	}
	return res;
}

void reconstruct(int v, int item)
{
	if (item == N + 1) return;
	if (pack(v, item) == pack(v, item + 1)) {
		reconstruct(v, item + 1);
	}
	else {
		ans.push_back(name[item]);
		reconstruct(v - volume[item], item + 1);
	}

}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> W;
		memset(dp, -1, sizeof(dp));
		ans.clear();
		for (int i = 1; i <= N; i++)
			cin >> name[i] >> volume[i] >> need[i];
		reconstruct(W, 1);
		cout << pack(W, 1) << " " << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
}