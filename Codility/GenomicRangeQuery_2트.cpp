#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    vector<int> result;

    vector<int> A(S.size()+1,0), C(S.size()+1,0), G(S.size()+1,0);
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'A')
            A[i + 1]++;
        else if (S[i] == 'C')
            C[i + 1]++;
        else if (S[i] == 'G')
            G[i + 1]++;
        A[i + 1] += A[i];
        C[i + 1] += C[i];
        G[i + 1] += G[i];
    }

    for (int i = 0; i < P.size(); i++) {
        int start = P[i], end = Q[i];
        if (A[start] != A[end + 1])
            result.push_back(1);
        else if (C[start] != C[end + 1])
            result.push_back(2);
        else if (G[start] != G[end + 1])
            result.push_back(3);
        else result.push_back(4);
    }
    return result;
}

int main()
{
    vector<int> p = { 2,5,0 };
    vector<int> q = { 4,5,6 };
    string str = "CAGCCTA";

    vector<int> res = solution(str, p, q);
    for (int i : res) {
        cout << i << " ";
    }
}