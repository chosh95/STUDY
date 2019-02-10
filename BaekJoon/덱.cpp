#include <iostream>
#include <string>
using namespace std;
int d[30000];
int front;
int back;
void pop_front()
{
	if (d[front] == 0) cout <<"-1\n";
	else {
		cout << d[front] << "\n";
		d[front] = 0;
		if(front<back) front += 1;
	}
}
void pop_back()
{
	if (d[back] == 0) cout <<"-1\n";
	else {
		cout << d[back]<<"\n";
		d[back] = 0;
		if (front < back) back -= 1;
	}
}
void size()
{
	if (back == front && d[front]==0) cout << "0\n";
	else cout << (back - front + 1) << "\n";
}
void empty()
{
	if (back == front && d[back] == 0) cout << "1\n";
	else cout << "0\n";
}
void front_f()
{
	if (d[front] == 0) cout << "-1\n";
	else cout << d[front] << "\n";
}
void back_b()
{
	if (d[back] == 0) cout << "-1\n";
	else cout << d[back] << "\n";
}
void push_front(int x)
{
	if (d[front] == 0) d[front] = x;
	else {
		front -= 1; 
		d[front] = x;
	}
}
void push_back(int x)
{
	if (d[back] == 0) d[back] = x;
	else {
		back += 1;
		d[back] = x;
	}
}
int main()
{
	int N;
	cin >> N;
	string str;
	int x;
	front = back = N+10;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		if (str == "pop_front") pop_front();
		else if (str == "pop_back") pop_back();
		else if (str == "size") size();
		else if(str == "empty") empty();
		else if (str == "front") front_f();
		else if (str == "back") back_b();
		else if (str == "push_front") {
			cin >> x;
			push_front(x);
		}
		else if (str=="push_back") {
			cin >> x;
			push_back(x);
		}
	}
}