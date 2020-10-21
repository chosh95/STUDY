#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
string str;

bool isPalin() {
	for (int i = 0; i < str.size() / 1; i++) 
		if (str[i] != str[str.size() - 1 - i]) 
			return false;
	
	return true;
}

int isAlmostPalin(int left, int right, int cnt) {
	if (left > right) return 0;
	
	if (str[left] == str[right]) return isAlmostPalin(left + 1, right - 1, cnt);
	if(cnt==0) return min(isAlmostPalin(left + 1, right, cnt + 1), isAlmostPalin(left, right - 1, cnt + 1));
	return cnt;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (isPalin()) cout << "0\n";
		else if (isAlmostPalin(0, str.size() - 1, 0) == 0) cout << "1\n";
		else cout << "2\n";
	}
}