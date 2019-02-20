#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char p[16];
vector<char> v;
int L, C;
void passwd(int curr,int count,int mo,int ja)
{
	if (count == L) {
		if (mo < 1 || ja < 2) return;
		for (int i = 0; i < L; i++) cout << v[i];
		cout << "\n";
		return;
	}
	if (curr >= C) return;
	if (L - mo - ja > C - curr) return;

	if (p[curr] == 'a' || p[curr] == 'e' || p[curr] == 'i' || p[curr] == 'o' || p[curr] == 'u') {
		v.push_back(p[curr]);
		passwd(curr + 1, count + 1, mo + 1, ja);
	}
	else {
		v.push_back(p[curr]);
		passwd(curr + 1, count + 1, mo, ja + 1);
	}
	v.pop_back();
	passwd(curr + 1, count, mo, ja);
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> p[i];
	sort(p, p + C);
	passwd(0, 0, 0, 0);
}