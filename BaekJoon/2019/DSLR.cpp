#include <iostream>
#include <memory.h>
#include <queue>
#include <string>
using namespace std;
bool p[10001];
int A, B;

int D(int num)
{
	num *= 2;
	num %= 10000;
	return num;
}
int S(int num)
{
	if (num == 0) num = 9999;
	else num -= 1;
	return num;
}
int L(int num)
{
	int t = num / 1000;
	num %= 1000;
	num *= 10;
	num += t;
	return num;
}
int R(int num)
{
	int t = num % 10;
	num /= 10;
	num += (t * 1000);
	return num;
}
void bfs()
{
	memset(p, false, sizeof(p));
	queue<pair<int, string>> q;
	q.push({ A,""});
	p[A] = true;
	while (!q.empty()) {
		int x = q.front().first;
		string tmp = q.front().second;
		q.pop();
		if (x == B) {
			cout << tmp << "\n";
			return;
		}
		int nx = D(x);
		if (p[nx] == false) {
			q.push({ nx,tmp + 'D' });
			p[nx] = true;
		}
		nx = S(x);
		if (p[nx] == false) {
			q.push({ nx,tmp + 'S' });
			p[nx] = true;
		}
		nx = L(x);
		if (p[nx] == false) {
			q.push({ nx,tmp + 'L' });
			p[nx] = true;
		}
		nx = R(x);
		if (p[nx] == false) {
			q.push({ nx,tmp + 'R' });
			p[nx] = true;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		bfs();
	}
	return 0;
}