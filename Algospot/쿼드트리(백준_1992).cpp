#include <iostream>
#include <string>
using namespace std;
int N;
int p[65][65];
int isWorB(int x, int y, int size) // x,y위치에서 size만큼의 구역이 white인지 black인지 구별, 아닐시 -1 반환
{
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (p[i][j] != p[x][y]) return -1;
		}
	}
	return p[x][y];
}
string quadtree(int x, int y, int size)
{
	if (isWorB(x, y, size) == 1)
		return "1";
	if (isWorB(x, y, size) == 0)
		return "0";
	string leftUpper = quadtree(x, y, size / 2);
	string rightUpper = quadtree(x, y + size / 2, size / 2);
	string leftLower = quadtree(x + size / 2, y, size / 2);
	string rightLower = quadtree(x + size / 2, y + size / 2, size / 2);
	return "(" + leftUpper + rightUpper + leftLower + rightLower + ")";
}
int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= N; j++) {
			if (tmp[j - 1] == '1') p[i][j] = 1;
			else p[i][j] = 0;
		}
	}
	cout<<quadtree(1, 1, N);

	return 0;
}