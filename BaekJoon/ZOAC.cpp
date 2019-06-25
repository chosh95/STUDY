#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int p[101];
char curmin;
int curpos, ssize, cnt;
string s;

void print(int start, int end)
{

	curmin = 'Z'+1;
	for (int i = start; i < end; i++) {
		if (s[i] < curmin && p[i] == 0 ) {
			curmin = s[i];
			curpos = i;
		}
	}
	p[curpos] = ++cnt;

	for (int i = 0; i < ssize; i++) {
		if (p[i] != 0)
			cout << s[i];
	}
	cout << "\n";
}
bool istrue()
{
	bool tmp = false;
	for (int i = curpos; i < ssize; i++) {
		if (p[i] != 0) continue;
		else {
			tmp = true;
			return true;
		}
	}
	return false;
}
int findCurPos()
{
	for(int i = ssize-1; i >= 0; i--) {
		if (p[i] == 0) return i+1;
	}
}
int findPrevPos()
{
	bool tmp = true;
	for (int i = 0; i < curpos; i++) {
		if (p[i] == 0) continue;
		else tmp = false;
	}
	if (tmp == true) return 0;

	int prevpos = 0, prevmax = 0;
	for (int i = 0; i < curpos; i++) {
		if (p[i] >= prevmax) {
			prevmax = p[i];
			prevpos = i;
		}
	}
	return prevpos;
}
int main()
{
	cin >> s;
	ssize = s.size();
	for (int i = 0; i < ssize; i++) {
		if (curpos == 0) print(0,ssize);
		else {
			if (istrue() && findCurPos() != curpos) print(curpos, ssize);
			else {
				curpos = findCurPos();
				int prevpos = findPrevPos();
				print(prevpos, curpos);
			}
		}
	}
}