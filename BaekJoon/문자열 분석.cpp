#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N = 100;
	while (N--) {
		string str;
		getline(cin, str);
		int a = 0, b = 0, c = 0, d = 0; //�ҹ���, �빮��, ����, ����
		if (str == "") return 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z') a++;
			else if (str[i] >= '0' && str[i] <= '9') c++;
			else if (str[i] == ' ') d++;
			else b++;
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}
}