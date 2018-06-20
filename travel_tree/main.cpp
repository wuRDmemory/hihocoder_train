#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <memory.h>
#include<bits/stdc++.h>

using namespace std;

const int maxN = 115;
// 表示该节点与其他节点的通断关系
bitset<maxN> connect[maxN];
vector<int> roads[maxN];
vector<int> order;
int passed[maxN][maxN];
bool yes = false;
int idx = 0;

int init() {
    for (int i = 0; i < maxN; ++i) {
        connect[i].reset();
        roads[i].clear();
        order.clear();
    }
    memset(passed, 0, sizeof(passed));
    yes = false;
    idx = 0;
    return 0;
}

int check_connect(int root, int parent) {
    connect[root][root] = 1;
    for (int i = 0; i < roads[root].size(); ++i) {
        int child = roads[root][i];
        if (child == parent)
            continue;
        // 继续检查子节点
        check_connect(child, root);
        // 或运算计算连通性
        connect[root] |= connect[child];
    }
    return 0;
}

int dfs(int root, int parent) {
    // 如果当前节点就是要通过的
    if (order[idx] == root) {
        idx++;
    }
    if (idx == order.size()) {
        yes = true;
        return 1;
    }
    // 遍历整个图
    while (idx < order.size()) {
        // 当遍历完当前的节点之后，如果没有找到任何出路的时候，一定要记得退出while循环
        int old_idx = idx;
        // 这是下一个要访问的地方
        int next = order[idx];
        for (int i = 0; i < roads[root].size(); ++i) {
            // 子节点
            int child = roads[root][i];
            // 遇到父节点了，跳过
            if (child == parent)
                continue;
            // 检查当前节点的该子节点是否可以到达下一个要去的地方
            // 同时必须要求当前节点到该子节点的路是没有走到的
            if (connect[child][next] && passed[root][child]) {
                passed[root][child] = 0;
                dfs(child, root);
                break;
            }
        }
        if (idx == old_idx) {
            // 遍历这个节点的子节点一无所获
            break;
        }
    }

    return 1;
}

int main() {
    int T = 0, n = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        // 初始化
        init();
        cin >> n;
        for (int j = 0; j < n-1; ++j) {
            int parent = 0, child = 0;
            cin >> parent >> child;
            roads[parent].push_back(child);
            roads[child].push_back(parent);
            // 表明已经经过了一次
            passed[parent][child] = passed[child][parent] = 1;
        }
        int m = 0;
        cin >> m;
        for (int k = 0; k < m; ++k) {
            int city = 0;
            cin >> city;
            order.push_back(city);
        }

        check_connect(1, -1);
        dfs(1, -1);
        if (yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 1;
}