#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int anchor = 1;
        int max_idx = 1;
        int max_len = 0;
        string s_copy="$#";
        for (char a : s) {
            s_copy.push_back(a);
            s_copy.push_back('#');
        }
        s_copy += "@";
        int* p = new int[s_copy.length()];
        p[0] = 0; p[1] = 1;
        for (int i=1; i<s_copy.size(); i++) {
            if (anchor + p[anchor]-1 > i) {
                p[i] = min(p[anchor-(i-anchor)], p[anchor]+anchor-i);
            } else {
                p[i] = 0;
            }

            while (s_copy[i-p[i]-1] == s_copy[i+p[i]+1]) {
                p[i]++;
            }

            if (p[i]+i >= p[anchor]+anchor) {
                anchor = i;
            }
            
            if (p[i] > max_len) {
                max_len = p[anchor];
                max_idx = i;
            }
        }
        cout << s_copy << endl;
        cout << max_idx << "  " << max_len << endl;
        string sub_str;
        for (int i=0; i<max_len*2; i++) {
            if (s_copy[max_idx+i-max_len]!='#') {
                sub_str.push_back(s_copy[max_idx+i-max_len]);
            }
        }
        return sub_str;
    }
};

int main(int argc, char* argv[]) {
    string str(argv[1]);
    Solution solution;
    string sub = solution.longestPalindrome(str);
    cout << sub << endl;
    return 1;
}
