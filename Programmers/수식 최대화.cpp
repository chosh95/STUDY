#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long cal(long long a, long long b, char op) {
    if (op == '-')
        return a - b;
    else if (op == '+')
        return a + b;
    return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> number;
    vector<char> op;

    long long num = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            number.push_back(num);
            num = 0;
            op.push_back(expression[i]);
        }
        else {
            num *= 10;
            num += (long long)(expression[i] - '0');
        }
    }
    number.push_back(num);

    string oper = "+-*";
    do {
        vector<long long> numberV = number;
        vector<char> opV = op;

        for (int i = 0; i < op.size(); i++) {
            vector<long long> tmpV;
            vector<char> opV;

            for (int j = 0; j < opV.size(); j++) {

            }
        }

    }while(next_permutation(oper.begin(), oper.end()));


    return answer;
}

int main()
{
    cout << solution("100-200*300-500+20");
}