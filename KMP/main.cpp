#include <iostream>
#include <vector>
#include <string>

using namespace std;

int KMP_seach(string& S, string& P) {
    int S_len = S.size(), P_len = P.size();
    int i = 0, j = -1, z = 0, cnt = 0;
    int* next = new int[P_len+1];
    next[0] = -1;
    // 获取next数组
    while ( i < P_len) {
        if (j == -1 || P[i] == P[j]) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
    i=0;j=0;
    while ( i<S_len) {
        if (S[i] == P[j] || j == -1) {
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == P_len) cnt++;
    }
    delete(next);

    return cnt;
}

int main() {
    int N = 0;
    vector<int> cnts;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str, pattern;
        cin >> pattern;
        cin >> str;
        cnts.push_back(KMP_seach(str, pattern));
    }

    for (int j = 0; j < cnts.size(); ++j) {
        cout << cnts[j] << endl;
    }
    return 0;
}