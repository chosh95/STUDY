#include <string>
#include <vector>
#include <iostream>
using namespace std;

string fun(string w) {
	string u, v;

	//1번 단계
	if (w == "") return "";

	//2번 단계
	for (int acnt = 0,bcnt=0, i = 0; i < w.size(); i++) {
		if (w[i] == '(') acnt++;
		else bcnt++;
		if (acnt == bcnt) { //균형잡힌 괄호 문자열로 분리
			u = w.substr(0,i+1);
			v = w.substr(i + 1);
			break;
		}
	}

	//u가 올바른 괄호 문자열인지 검사
	int cnt = 0;
	for (int i = 0; i < u.size(); i++){
		if (cnt==0 && u[i] == ')') {
			cnt++;
			continue;
		}
		if (u[i] == '(') cnt++;
		else cnt--;
	}

	if (cnt == 0) {
		//3번 단계
		v = fun(v);
		//3.1번 단계
		return u + v;
	}

	//4번 단계
	else {
		string tmp = "("; //4.1
		tmp += fun(v); //4.2
		tmp += ")"; //4.3
		u.erase(0,1); //4.4
		u.erase(u.size()-1,1);
		for (int i = 0; i < u.size(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		return tmp + u; //4.5
	}
}

string solution(string p) {
	string answer = "";
	answer = fun(p);
	return answer;
}

int main()
{
	cout << solution(")(") << endl;
	cout << solution("(()())()") << endl;
	cout << solution("()))((()");
}