#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int N;
	cin >> N;
	deque<int> d;
	for (int i = 1; i <= N; i++) d.push_back(i);
	while (d.size() > 1) {
		d.pop_front();
		int tmp = d.front();
		d.pop_front();
		d.push_back(tmp);
	}
	cout << d.front();
}