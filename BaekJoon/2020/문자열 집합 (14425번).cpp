#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> s;
int N, M;
string str;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str)!=s.end()) res++;
	}
	cout << res;
}