#include <iostream>
using namespace std;
int v[203];
int N, V;

int main()
{
	cin >> N;
	for (int i = 1, tmp; i <= N; i++) {
		cin >> tmp;
		if (tmp < 0) v[tmp + 201] += 1;
		else v[tmp] += 1;
	}
	cin >> V;
	if (V < 0) cout << v[V + 201];
	else cout << v[V];
}