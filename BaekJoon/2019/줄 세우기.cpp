#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N;

int main()
{
	cin >> N;	
	for (int i = 1, a; i <= N; i++) {
		cin >> a;
		if (a == 0) v.push_back(i);
		else {
			v.insert(v.end() - a , i);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}
}