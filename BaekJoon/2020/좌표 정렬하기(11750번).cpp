#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int, int> p[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		cout << p[i].first <<" "<< p[i].second << "\n";
	}
}