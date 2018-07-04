#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
int dp[505][100005] = {0};

int bag_arrayNM(int N, int M, vector<pair<int, int> >& nv) {
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (j>=nv[i].first)
                dp[i][j] = max(dp[i+1][j], dp[i][j-nv[i].first]+nv[i].second);
            else
                dp[i][j] = dp[i+1][j];
        }
    }
    return 1;
}
#else
int dp[100005] = {0};

int bag_array1M(int N, int M, vector<pair<int, int> >& nv) {
    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (j>=nv[i].first)
                dp[j] = max(dp[j], dp[j-nv[i].first]+nv[i].second);
        }
    }
    return 0;
}
#endif

int main() {
    int N=0, M=0;
    cin >> N >> M;
    vector<pair<int, int> > nv;
    for (int i = 0; i < N; ++i) {
        int need = 0, value = 0;
        cin >> need >> value;
        nv.push_back(make_pair(need, value));
    }
    sort(nv.begin(), nv.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    });
    bag_array1M(N, M, nv);
    cout << dp[M-1];
    return 1;
}