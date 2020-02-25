#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
pair<int, string> p[100001];
int N;

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;
	stable_sort(p, p + N);
	for (int i = 0; i < N; i++) cout << p[i].first << " " << p[i].second << "\n";
}