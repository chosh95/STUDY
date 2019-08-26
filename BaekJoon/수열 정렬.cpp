#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v;
int b[51];

int main()
{
	cin >> N;
	for (int i = 0, tmp; i < N; i++) {
		cin >> tmp;
		v.push_back({ tmp,i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		b[v[i].second] = i;
	}
	for (int i = 0; i < N; i++) cout << b[i] << " ";
}