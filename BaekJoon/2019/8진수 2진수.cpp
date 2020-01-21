#include <iostream>
#include <string>
using namespace std;

int main()
{
	string N;
	string str = "";
	cin >> N;
	if (N == "0") {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N.size(); i++) {
		if (N[i] == '1' && i == 0) str += '1';
		else if (N[i] == '2' && i == 0) str += "10";
		else if (N[i] == '3' && i == 0) str += "11";
		else if (N[i] == '0') str += "000";
		else if (N[i] == '1') str += "001";
		else if (N[i] == '2') str += "010";
		else if (N[i] == '3') str += "011";
		else if (N[i] == '4') str += "100";
		else if (N[i] == '5') str += "101";
		else if (N[i] == '6') str += "110";
		else if (N[i] == '7') str += "111";
		else if (N[i] == '8') str += "1000";
		else if (N[i] == '9') str += "1001";
	}
	cout << str;
}