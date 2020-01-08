#include <iostream>
#include <string>
using namespace std;
int C, pos; //string 검색 위치 저장, iter 대신 사용
string str;

string quadtree()
{
	char cur = str[pos++];
	if (cur == 'w' || cur == 'b') return string(1,cur);
	string leftUpper = quadtree();
	string rightUpper = quadtree();
	string leftLower = quadtree();
	string rightLower = quadtree();
	return "x" + leftLower + rightLower + leftUpper + rightUpper;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> str;
		pos = 0;
		cout << quadtree() << "\n";
	}
}