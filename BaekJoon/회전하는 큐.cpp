#include <iostream>
#include <queue>
using namespace std;
int q[51];
int p[51];
int N, M, front, back, res=0;

void fun1()
{
	for (int i = 1; i <= back-1; i++) {
		q[i] = q[i + 1];
	}
	q[back] = 0;
	back -= 1;
}
void fun2()
{
	int tmp = q[front];
	for (int i = 1; i <= back - 1; i++) {
		q[i] = q[i + 1];
	}
	q[back] = tmp;
}
void fun3()
{
	int tmp = q[back];
	for (int i = back; i >= 2; i--) {
		q[i] = q[i - 1];
	}
	q[front] = tmp;
}
void que(int m)
{
	if (q[1] == m) fun1();
	else {
		int idx;
		for (int i = front; i <= back; i++) {
			if (q[i] == m) {
				idx = i;
				break;
			}
		}
		int f2 = idx - front; //fun2를 실행해야 하는 횟수
		int f3 = back - idx + 1;//fun3 "
		if (f2 >= f3) {
			while (q[1] != m) {
				fun3();
				res++;
			}
			fun1();
		}
		else {
			while (q[1] != m) {
				fun2();
				res++;
			}
			fun1();
		}
	}
	return;
}
int main()
{
	cin >> N >> M;
	front = 1, back = N;
	for (int i = 1; i <= N; i++) q[i] = i; //queue 행렬 초기화

	for (int i = 1; i <= M; i++) {
		cin >> p[i];
		que(p[i]);
	}
	cout << res;
	
}