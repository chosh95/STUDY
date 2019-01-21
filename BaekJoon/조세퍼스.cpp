#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; i++)
		v.push_back(i);
	
		cout << "<" << v[M-1];
		v.erase(v.begin() + (M-1));
		int i = M - 1;

		while (!v.empty()) {
			i += M - 1;
			i %= v.size();
			cout << ", " << v[i];
			v.erase(v.begin() + i);
		}
		cout << ">";
}