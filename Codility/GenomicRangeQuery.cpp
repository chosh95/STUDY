#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> range;

int init(int left, int right, int node, string S) {
    if (left == right) {
        int cur;
        if (S[left] == 'A') cur = 1;
        else if (S[left] == 'C') cur = 2;
        else if (S[left] == 'G') cur = 3;
        else cur = 4;
        return range[node] = cur;
    }
    int mid = (left + right) / 2;
    return range[node] = min(init(left, mid, node * 2, S),init(mid + 1, right, node * 2 + 1, S));
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if (nodeRight < left || right < nodeLeft) return 987654321;
    if (nodeLeft <= left && right <= nodeRight) return range[node];
    int mid = (left + right) / 2;
    return min(query(left, mid, node * 2, nodeLeft, nodeRight), query(mid + 1, right, node * 2 + 1, nodeLeft, nodeRight));
}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    vector<int> result;

    range.resize(S.size() * 4);
    init(0, S.size() - 1, 1, S);

    for (int i = 0; i < P.size(); i++) 
        result.push_back(query(0, S.size() - 1, 1, P[i], Q[i]));
    
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