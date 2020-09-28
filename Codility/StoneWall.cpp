#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<int>& H) {
    // write your code in C++14 (g++ 6.2.0)
    stack<int> st;
    int answer = 0;

    for (int i = 0; i < H.size(); i++){
        while (!st.empty() && st.top() > H[i])
            st.pop();
        if (st.empty() || st.top() < H[i]) {
            st.push(H[i]);
            answer++;
            continue;
        }
        if (st.top() == H[i]) {
            continue;
        }
    }
    return answer;
}

int main()
{
    vector<int> input = { 8,8,5,7,9,8,7,4,8};
    cout << solution(input);
}