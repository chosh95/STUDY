#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
bool set[22];

int main()
{
	int M;
	scanf("%d", &M);
	char s[10];
	int x;
	while (M--) {
		scanf("%s", &s);
		if (s[0] == 'a' && s[1] == 'd') {
			scanf("%d", &x);
			set[x] = true;
		}
		else if (s[0] == 'c') {
			scanf("%d", &x); 
			if (set[x]==true) printf("1\n");
			else printf("0\n");
		}
		else if (s[0] == 'r') {
			scanf("%d", &x); 
			set[x] = false;
		}
		else if (s[0] == 't') {
			scanf("%d", &x); 
			if (set[x]==true) set[x] = false;
			else set[x] = true;
		}
		else if (s[0] == 'a' && s[1] == 'l') {
			for (int i = 1; i <= 21; i++) set[i] = true;
		}
		else {
			for (int i = 1; i <= 21; i++) set[i] = false;
		}
	}
}