#include <iostream>
#include <string>
using namespace std;
string str[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	long long res = 0;
	for (int i = 0; i < 10; i++){
		if (str[i] == a) {
			res = i;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (str[i] == b) {
			res *= 10;
			res += i;
			break;
		}
	}
	int idx;
	for (int i = 0; i < 10; i++) {
		if (str[i] == c) {
			idx = i;
		}
	}
	for (int i = 0; i <= idx-1; i++) {
		res *= 10;
	}
	cout << res;
}