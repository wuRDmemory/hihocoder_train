#include <iostream>

using namespace std;

int pyrmiod[101][101] = {0};
int pyrmiod_max[101][101] = {0};

int get_max(int n, int room, int max_n) {
    if (n == max_n) {
        pyrmiod_max[n][room] = pyrmiod[n][room];
        return pyrmiod[n][room];
    } else {
        int max1 = 0, max2 = 0;
        if (pyrmiod_max[n+1][room] != 0) {
            max1 = pyrmiod_max[n+1][room];
        } else {
            max1 = get_max(n+1, room, max_n);
        }

        if (pyrmiod_max[n+1][room+1] != 0) {
            max2 = pyrmiod_max[n+1][room+1];
        } else {
            max2 = get_max(n+1, room+1, max_n);
        }

        pyrmiod_max[n][room] = pyrmiod[n][room] + max(max1, max2);
        return pyrmiod_max[n][room];
    }
}

int main() {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> pyrmiod[i][j];
        }
    }

    cout << get_max(0,0, N-1);
    return 0;
}