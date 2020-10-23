#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> m;
vector<string> v;
int parent[501];

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(string A, string B) {
	int parentA = find(m[A]);
	int parentB = find(m[B]);
	if(parentA != parentB)
		parent[parentB] = parentA;
	else {
		parent[m[A]] = m[A];
		parent[parentB] = m[A];
	}

	find(parentB);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	string a, b, c, d, e;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		m[c] = i;
		parent[m[c]] = i;
		v.push_back(c);
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d >> e;
		string countryA = "";
		for (int j = 0; j < c.size(); j++) {
			if (c[j] == ',') break;
			countryA += c[j];
		}
			
		string countryB = "";
		int isWin = 0, idx = 0;
		for (int j = 0; j < e.size(); j++) {
			if (e[j] == ',') break;
			countryB += e[j];
		}

		isWin = e[e.size() - 1] - '0';

		if (isWin == 1)
			merge(countryA, countryB);
		else
			merge(countryB, countryA);
	}

	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (parent[i] == i)
			ans++;
	cout << ans << endl;

	for (int i = 0; i < v.size(); i++) {
		if (parent[m[v[i]]] == m[v[i]]) {
			cout << "Kingdom of " << v[i] << "\n";
		}
	}
}