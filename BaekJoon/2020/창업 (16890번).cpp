#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
deque<char> a;
deque<char> b;

int main()
{
	string strA, strB;
	cin >> strA >> strB;

	sort(strA.begin(), strA.end());
	sort(strB.begin(), strB.end(),greater<char>());

	for (int i = 0; i < (int)(strA.size() + 1) / 2; i++) a.push_back(strA[i]);
	for (int i = 0; i < strB.size() / 2; i++) b.push_back(strB[i]);

	string front = "", back = "";
	for (int i = 0; i < strA.size(); i++) {
		if (i % 2)
			if (a.empty() || a.front() < b.front()) front += b.front(), b.pop_front();
			else back += b.back(), b.pop_back();
		else
			if (b.empty() || a.front() < b.front()) front += a.front(), a.pop_front();
			else back += a.back(), a.pop_back();
	}

	reverse(back.begin(), back.end());
	cout << front << back;
}