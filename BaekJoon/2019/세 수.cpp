#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int p[3];
	cin>>p[0]>>p[1]>>p[2];
	sort(p,p+3);
	cout<<p[1];
}
