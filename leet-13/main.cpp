#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> char2int_map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int romanToInt(string s) {
        int res = 0;
        int max_v = 0;
        for (int i = s.length()-1; i>=0; i--) {
            int num = char2int_map[s[i]];
            if (num >= max_v) {
                res  = res + num;
            } else {
                res = res - num;
            }
            max_v = max(max_v, num);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    cout << solution.romanToInt(argv[1]) << endl;
    return 1;
}
