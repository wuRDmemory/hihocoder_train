#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty()) {
            return s;
        }

        int len = (int)s.length();
        int circle = max(2*(numRows-1),1);
        string sub[numRows];
        
        for (int i=0; i<len; i++) {
            int mod = i%circle;
            if (mod < numRows) {
                sub[mod] += s[i];
            } else {
                sub[circle-mod] += s[i];
            }
        }

        string total = sub[0];
        for (int i=1;i<numRows;i++) {
            total += sub[i];
        }
        return total;
    }
};

int main(int argc, char* argv[]) {
    string str(argv[1]);
    int num = atoi(argv[2]);

    Solution solution;
    string res = solution.convert(str, num);
    cout << res << endl;
    return 1;
}
