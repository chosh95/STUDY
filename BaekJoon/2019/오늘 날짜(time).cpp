#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	struct tm *t;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	printf("%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}