#include <iostream>

using namespace std;

class Solution {
public:
    long reverse(long x) {
        int sign = x>0?1:-1;
        long res = 0, mul = 1;
        string number = to_string(abs(x));
        for (int i=0; i<number.length(); i++) {
            res += mul*(number[i]-'0');
            mul*=10;
        }
        return sign*res;
    }
};

int main(int argc, char* argv[]) {
    string str(argv[1]);
    long x = atol(str.c_str());
    cout << x << endl;
    Solution solution;
    cout << solution.reverse(x) << endl;
    return 1;
}
