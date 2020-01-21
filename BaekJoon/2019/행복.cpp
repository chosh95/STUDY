#include <iostream>
#include <algorithm>
using namespace std;
int p[1001];
int N;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin>>p[i];
	sort(p, p + N);
	cout << p[N-1] - p[0];
}