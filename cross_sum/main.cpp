#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cross_sum(long num, char& sign) {
    if (num / 10 == 0) {
        return int(sign*num);
    }

    int mod = num % 10;
    mod *= sign;
    num = num / 10;
    sign = -sign;
    return mod + cross_sum(num, sign);
}

bool get_cross_sum(long num, int k) {
    char sign = 1;
    int res = cross_sum(num, sign);

    res *= sign;
    return res == k;
}

int main() {

    long l = 0, r = 0, k = 0, res = 0;
//    cin >> l >> r >> k;
    string name;
    getline(cin, name);
    cout << name << endl;
    for (int i = l; i <= r; ++i) {
        if (get_cross_sum(i, k)) {
            res += i;
        }
    }

    cout << res << endl;
    return 0;
}