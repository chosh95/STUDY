#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int num = 665;
	while (N > 0) {
		num++;
		string str = to_string(num);
		if (str.find("666") != string::npos) N--;
	}
	cout << num;
}