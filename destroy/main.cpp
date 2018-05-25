#include <iostream>
#include <vector>

using namespace std;

typedef struct Magic_t {
    int v0, v1, v2, v3;
}Magic;

int main() {
    int N = 0;
    cin >> N;
    vector<Magic> inputs;
    for (int i = 0; i < N; ++i) {
        int v0 = 0, v1 = 0, v2 = 0;
        cin >> v0 >> v1 >> v2;
        Magic magic;
        magic.v0 = v0;
        magic.v1 = v1;
        magic.v2 = v2;
        magic.v3 = 0;
        inputs.push_back(magic);
    }
    int M = 0;
    cin >> M;
    vector<Magic> operates;
    Magic magic;
    magic.v0 = 0;
    magic.v1 = 0;
    magic.v2 = 0;
    magic.v3 = 0;
    operates.push_back(magic);
    for (int j = 0; j < M; ++j) {
        int v0 = 0, v1 = 0, v2 = 0;
        cin >> v0 >> v1 >> v2;
        Magic magic;
        magic.v0 = v0;
        magic.v1 = v1-1;
        magic.v2 = v2-1;
        magic.v3 = 0;
        operates.push_back(magic);
    }

    int sum_magic = 0;
    for (int k = 1; k <= M; ++k) {
        Magic opt = operates[k];
        for (int i = opt.v1; i <= opt.v2; ++i) {
            int now_magic = inputs[i].v0 + (opt.v0 - inputs[i].v3)*inputs[i].v2;
            inputs[i].v3 = opt.v0;
            inputs[i].v0 = 0;
            now_magic = std::min(now_magic, inputs[i].v1);
            sum_magic += now_magic;
        }
    }

    cout<<sum_magic;
    return 0;
}