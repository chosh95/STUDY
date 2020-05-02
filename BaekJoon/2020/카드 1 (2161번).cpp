#include <iostream>
#include <deque>
using namespace std;
deque<int> d;
int N;

int main()
{
	int idx = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		d.push_back(i);

	while (d.size() != 1) {
		cout << d.front() << " ";
		d.pop_front();
		int tmp = d.front();
		d.pop_front();
		d.push_back(tmp);		
	}
	cout << d.front();
}