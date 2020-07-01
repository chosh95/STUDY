#include <iostream>
#include <map>
#include <string>
using namespace std;
int N, M;
map<string, string> m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	string site, pwd;
	while (N--) {
		cin >> site >> pwd;
		m[site] = pwd;
	}
	while (M--) {
		cin >> site;
		cout << m[site] << "\n";
	}
}