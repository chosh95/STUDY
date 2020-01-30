#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int C, N;
int r[201], p[201]; //필요한 재료 양, 이미 넣은 재료 양
int res[201]; //더 넣어야 하는 재료 양

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
// a/b보다 같거나 큰 자연수
int ceil(int a, int b)
{
	return (a + b - 1) / b;
}
void potion()
{
	int b = r[0];

	//레시피들의 최대 공약수를 구한다.
	for (int i = 1; i < N; i++)
		b = gcd(b, r[i]);
	//그후 최대공약수로 모두 나눈다.
	for (int i = 0; i < N; i++)
		r[i] /= b;

	//X를 구한다.
	int X = b;
	for (int i = 0; i < N; i++)
		X = max(X, ceil(p[i], r[i]));

	//recipe에 X를 곱한다.
	for (int i = 0; i < N; i++)
		r[i] *= X;

	//정답을 구한다.
	for (int i = 0; i < N; i++)
		res[i] = r[i] - p[i];

}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> r[i];
		for (int i = 0; i < N; i++)
			cin >> p[i];
		potion();
		for (int i = 0; i < N; i++)
			cout << res[i] << " ";
		cout << endl;
	}
}