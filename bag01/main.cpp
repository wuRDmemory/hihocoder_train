#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bag01[501][100001]={0};

int main() {
    int data_cnt=0, value_sum=0;
    cin >> data_cnt >> value_sum;
    vector<pair<int, int> > data;
    data.reserve(data_cnt);
    for (int i = 0; i < data_cnt; ++i) {
        int need=0, value=0;
        cin >> need >> value;
        data.push_back(make_pair(need, value));
    }

    sort(data.begin(), data.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    for (int i = 0; i < data_cnt; ++i) {
        auto data_i = data[i];
        for (int j = 0; j < value_sum; ++j) {
            if (i == 0) {
                if (j >= data_i.first) {
                    bag01[i][j] = data_i.second;
                }
            } else {
                if (j >= data_i.first) {
                    int weight = data_i.first;
                    bag01[i][j] = std::max(data_i.second+bag01[i-1][j-weight], bag01[i-1][j]);
                } else {
                    bag01[i][j] = bag01[i-1][j];
                }
            }
        }
    }

    int show_data = bag01[data_cnt-1][value_sum-1];
    cout << show_data;
    return 0;
}