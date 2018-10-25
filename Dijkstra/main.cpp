#include <iostream>
#include <vector>
using namespace std;

int dis[100] = {0}; // = new int[N];
int vis[100] = {0}; //ew int[N];
vector<int> nodes[100];

int search_dijsktra(int** edge_table, int N) {

    for (int i = 0; i < N; ++i) {
        dis[i] = edge_table[0][i];
        vis[i] = 0;
    }
    // begin search
    for (int i = 1; i < N; ++i) {
        // find small
        int min_w = 999, min_index = -1;
        for (int j=1; j<N; j++) {
            // if this is best, continue
            if (vis[j]) continue;
            // else find other node
            if (dis[j] != INT32_MAX && dis[j] < min_w) {
                min_w = dis[j];
                min_index = j;
            }
        }
        if (min_index == -1) continue;

        // visit this point
        vis[min_index] = 1;
        if (nodes[min_index].empty()) {
            nodes[min_index].emplace_back(min_index);
        }
        // slack neighbor
        for (int k = 0; k < N; ++k) {
            if (k != min_index && edge_table[min_index][k] != INT32_MAX) {
                // we have edge here
                if (dis[min_index] + edge_table[min_index][k] < dis[k]) {
                    dis[k] = dis[min_index] + edge_table[min_index][k];
                    nodes[k] = nodes[min_index];
                    nodes[k].emplace_back(k);
                }
            }
        }
    }

    return 1;
}

int main() {
    // N nodes and M edges
    int N=0, M=0;
    cin >> N >> M;
    int** edge = new int*[N];
    for (int j = 0; j < N; ++j) {
        edge[j] = new int[N];
        for (int i = 0; i < N; ++i) {
            if (i == j)
                edge[j][i] = 0;
            else
                edge[j][i] = INT32_MAX;
        }
    }
    // 输入
    for (int i = 0; i < M; ++i) {
        int n1=0, n2=0, w=0;
        cin >> n1 >> n2 >> w;
        edge[n1-1][n2-1] = w;
    }

    search_dijsktra(edge, N);

    return 0;
}