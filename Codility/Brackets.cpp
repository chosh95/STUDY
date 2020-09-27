#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int solution(string S) {
    stack<char> st;
    for (int i = 0; i < S.size(); i++) {
        if (st.empty())
            st.push(S[i]);
        else {
            if (S[i] == ')') {
                if (st.top() == '(')
                    st.pop();
                else
                    return 0;
            }
            else if (S[i] == ']') {
                if (st.top() == '[')
                    st.pop();
                else
                    return 0;
            }
            else if (S[i] == '}') {
                if (st.top() == '{')
                    st.pop();
                else
                    return 0;
            }
            else
                st.push(S[i]);
        }
    }
    if (st.empty()) return 1;
    else return 0;
}

int main()
{
    cout << solution("{}}{");
}