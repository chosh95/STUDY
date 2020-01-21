#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct bus {
	int stt, end, cnt;
};
bool cmp(bus& a, bus& b)
{
	if (a.stt != b.stt) return a.stt < b.stt;
	return a.end > b.end;
}
bool chk[500001];
vector<bus> reg, irreg;
int N, M;

int main()
{
	cin >> N >> M;
	int maxend = 0, minstt = N - 1;
	for (int i = 1; i <= M; i++) {
		bus tmp;
		scanf("%d %d", &tmp.stt, &tmp.end);
		tmp.cnt = i;
		if (tmp.stt < tmp.end) reg.push_back(tmp);
		else {
			irreg.push_back(tmp);
			maxend = max(tmp.end, maxend);
			minstt = min(tmp.stt, minstt);
		}
	}
	sort(reg.begin(), reg.end(), cmp);
	sort(irreg.begin(), irreg.end(), cmp);
	int cur = 0;
	for (int i = 0; i < reg.size(); i++) {
		if (reg[i].stt >= minstt) chk[reg[i].cnt] = true;
		if (reg[i].end <= maxend) chk[reg[i].cnt] = true;
		if (reg[i].end <= cur) chk[reg[i].cnt] = true;
		else cur = reg[i].end;
	}
	cur = -1;
	for (int i = 0; i < irreg.size(); i++) {
		if (irreg[i].end <= cur) chk[irreg[i].cnt] = true;
		else cur = irreg[i].end;
	}
	for (int i = 1; i <= M; i++) {
		if (!chk[i]) cout << i << " ";
	}
}
