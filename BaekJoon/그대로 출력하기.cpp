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
	scanf는 ' ', '\t', '\n' 즉 공백, 탭, 개행을 모두 인식
	fgets는 개행만을 인식해서 공백도 포함, 입력에 실패하면 '\0'을 return해서
		입력이 끝났음을 알 수 있다.
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