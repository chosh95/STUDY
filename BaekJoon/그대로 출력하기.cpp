#include <iostream>
#include <string>
using namespace std;


int main()
{
	char s[101];
	while (fgets(s,101,stdin)) {
		printf("%s", s);
	}
}
/*
	scanf�� ' ', '\t', '\n' �� ����, ��, ������ ��� �ν�
	fgets�� ���ุ�� �ν��ؼ� ���鵵 ����, �Է¿� �����ϸ� '\0'�� return�ؼ�
		�Է��� �������� �� �� �ִ�.
*/
/*
int main() {
	int a;
	while (1) {


		a = getchar();

		if (a == EOF) {
			break;
		}
		putchar(a);


	}
	return 0;

}
*/